#include <vector>
#include <utility>
#include <algorithm>

class MyCalendarTwo {
private:
    std::vector<std::pair<int, int>> singleBookings;
    std::vector<std::pair<int, int>> doubleBookings;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (const auto& interval : doubleBookings) {
            if (start < interval.second && end > interval.first) {
                return false;
            }
        }

        for (const auto& interval : singleBookings) {
            if (start < interval.second && end > interval.first) {
                doubleBookings.push_back({std::max(start, interval.first), std::min(end, interval.second)});
            }
        }

        singleBookings.push_back({start, end});

        std::sort(doubleBookings.begin(), doubleBookings.end());

        return true; 
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
