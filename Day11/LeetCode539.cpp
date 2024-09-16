#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> changeToMinutes(std::vector<std::string>& timePoints) {
        int totMin;
        std::vector<int> minVec;

        for(auto& time : timePoints) {
            totMin = 0;

            std::string hour = time.substr(0,2);
            std::string min  = time.substr(3);

            totMin = stoi(min) + (stoi(hour) * 60);
            minVec.emplace_back(totMin);
        }

        return minVec;
    }

    int findMinDifference(std::vector<std::string>& timePoints) {

        std::vector<int> minVec = changeToMinutes(timePoints);
        std::sort(minVec.begin(), minVec.end());

        int minDifference = INT_MAX;

        for (int i = 1; i < minVec.size(); ++i) {
            int difference = minVec[i] - minVec[i - 1];

            if (difference < minDifference) {
                minDifference = difference;
            }
        }

        int wrapAroundDifference = (1440 - minVec.back()) + minVec.front();
        minDifference = std::min(minDifference, wrapAroundDifference);
    
        return minDifference;
    }
};