#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
        std::vector<int> n_rolls;
        n_rolls.resize(n);
        int min_value = 1 * n;
        int max_value = 6 * n;

        int m = rolls.size();

        int target_sum = (m + n) * mean - std::accumulate(rolls.begin(), rolls.end(), 0);

        if (target_sum < min_value || target_sum > max_value) {
            return {}; 
        }

        int base_value = target_sum / n;
        int remainder = target_sum % n;

        std::fill(n_rolls.begin(), n_rolls.end(), base_value);

        for (int i = 0; i < remainder; ++i) {
            n_rolls[i] += 1;
        }

        return n_rolls; 
    }
};