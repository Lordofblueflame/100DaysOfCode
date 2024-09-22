#include <algorithm>

class Solution {
public:
long long countSteps(long long prefix, long long n) {
        long long steps = 0;
        long long first = prefix;
        long long last = prefix;

        while (first <= n) {
            steps += std::min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {
        long long current = 1;
        k--;  

        while (k > 0) {
            long long steps = countSteps(current, n);

            if (steps <= k) {
                current++;
                k -= steps;
            } else {
                current *= 10;
                k--;
            }
        }

        return current;
    }
};