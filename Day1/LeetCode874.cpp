#include <vector>
#include <set>
#include <numeric>

class Solution {
public:
    // Directions: 0 -> North, 1 -> East, 2 -> South, 3 -> West
    void directionInterpreter(int& direction, const int& move) {
        if (move == -2) {
            direction = (direction + 3) % 4;
        } else if (move == -1) {
            direction = (direction + 1) % 4;
        }
    }

    void moveForward(std::vector<int>& currentPosition, const int& direction, const int& distance, const std::set<std::pair<int, int>>& obstacles) {
    int x = currentPosition[0];
    int y = currentPosition[1];

    for (int i = 0; i < distance; ++i) {
        // Move one step at a time
        if (direction == 0) { // North
            y++;
        } else if (direction == 1) { // East
            x++;
        } else if (direction == 2) { // South
            y--;
        } else if (direction == 3) { // West
            x--;
        }

        if (obstacles.find({x, y}) != obstacles.end()) {
            return;
        }

        currentPosition[0] = x;
        currentPosition[1] = y;
    }
}

    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
        int direction = 0; 
        int maxDistanceSquared = 0;
        std::vector<int> currentPosition = {0, 0};
        std::set<std::pair<int, int>> obstacleSet;   

        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }


        for (const int& command : commands) {
            if (command > 0) {
                moveForward(currentPosition, direction, command, obstacleSet);
                int currentDistanceSquared = currentPosition[0] *
                currentPosition[0] + currentPosition[1] * currentPosition[1];

                maxDistanceSquared = std::max(maxDistanceSquared, currentDistanceSquared);
            }

            if (command < 0) { 
                directionInterpreter(direction, command);
            }
        }

        return maxDistanceSquared;
    }
};
