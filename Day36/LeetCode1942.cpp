#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

struct Event {
    int time;
    int friendId;

    Event(int t, int id) : time(t), friendId(id) {}
};

class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        int n = times.size();
        std::vector<Event> events;

        for (int i = 0; i < n; i++) {
            events.emplace_back(times[i][0], i);
            events.emplace_back(times[i][1], ~i);
        }

        std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
            return a.time < b.time || (a.time == b.time && a.friendId < b.friendId);
        });

        std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> occupiedChairs;

        for (int i = 0; i < n; i++) {
            availableChairs.push(i);
        }

        for (const auto& event : events) {
            int time = event.time;
            int friendIndex = event.friendId;

            while (!occupiedChairs.empty() && occupiedChairs.top().first <= time) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            if (friendIndex >= 0) {
                int chair = availableChairs.top();
                availableChairs.pop();
                if (friendIndex == targetFriend) {
                    return chair;
                }
                occupiedChairs.push({times[friendIndex][1], chair});
            }
        }

        return -1;
    }
};