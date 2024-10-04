#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
/*
    std::vector<std::pair<int,int>> divideToTeams(std::vector<int>& skills) {
        std::sort(skills.begin(),skills.end());

        std::vector<std::pair<int,int>> retVec;

        int last_idx = skills.size()-1;
        int sum = 0;

        for(std::size_t i = 0 ; i < (last_idx + 1)/2; i++ ) {
            int currentSum = skills[i] + skills[last_idx-i];

            if(sum == 0) {
                sum = currentSum;
            }

            if(sum != currentSum ) {
                return std::vector<std::pair<int,int>>();
            }

            retVec.emplace_back(std::make_pair(skills[i],skills[last_idx-i]));
        }

        return retVec;
    }

    long long calculateChemisty(const std::vector<std::pair<int,int>> teamsVec) {
        if(teamsVec.empty()) return -1;

        long long retSum = 0;

        for(const auto& [t1,t2] : teamsVec) {
            retSum += t1*t2;
        }

        return retSum;
    }
*/
    long long calculateChemisty(std::vector<int>& skills) {
        std::sort(skills.begin(),skills.end());

        int last_idx = skills.size()-1;
        int sum = 0;
        long long chemistry = 0;
        for(std::size_t i = 0 ; i < (last_idx + 1)/2; i++ ) {
            int currentSum = skills[i] + skills[last_idx-i];

            if(sum == 0) {
                sum = currentSum;
            }

            if(sum != currentSum ) {
                return -1;
            }

            chemistry += skills[i]*skills[last_idx-i];
        }

        return chemistry;
    }

    long long dividePlayers(std::vector<int>& skill) {
        if(skill.size() == 2) {
            return skill[0] * skill[1];
        }

        return calculateChemisty(skill);
        
//alternative
//std::vector<std::pair<int,int>> teamsVec = divideToTeams(skill);

//return calculateChemisty(teamsVec);
    }   
};