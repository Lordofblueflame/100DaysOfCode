#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    // Calculate frequency of remainders (ensuring non-negative remainders)
    for (int num : arr) {
        int remainder = ((num % k) + k) % k;  // Ensures non-negative remainder
        freq[remainder]++;
    }

    // Check for valid pairs
    for (auto& [rem, count] : freq) {
        if (rem == 0) {
            // If the remainder is 0, there must be an even count of such elements
            if (count % 2 != 0) {
                return false;
            }
        } else {
            // For any other remainder rem, the count of rem must equal the count of k - rem
            int complement = k - rem;
            if (freq[rem] != freq[complement]) {
                return false;
            }
        }
    }

    return true;
}