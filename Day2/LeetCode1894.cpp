#include <vector>
#include <numeric>

int chalkReplacer(std::vector<int>& chalk, int k) {
    long long sum = std::accumulate(chalk.begin(), chalk.end(), 0LL); 

    k = k % sum;

    for (int i = 0; i < chalk.size(); ++i) {
        if (k < chalk[i]) {
            return i;
        }
        k -= chalk[i];
    }

    return -1;
}