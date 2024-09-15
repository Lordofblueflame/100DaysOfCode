#include <unordered_map>
#include <string>

class Solution {
public:

    int findTheLongestSubstring(std::string s) {
        std::unordered_map<int, int> mask_index;
        mask_index[0] = -1;
        
        int bitmask = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                bitmask ^= (1 << 0);
            } else if (s[i] == 'e') {
                bitmask ^= (1 << 1);
            } else if (s[i] == 'i') {
                bitmask ^= (1 << 2);
            } else if (s[i] == 'o') {
                bitmask ^= (1 << 3);
            } else if (s[i] == 'u') {
                bitmask ^= (1 << 4);
            }
            
            if (mask_index.find(bitmask) != mask_index.end()) {
                maxLength = std::max(maxLength, i - mask_index[bitmask]);
            } else {
                mask_index[bitmask] = i;
            }
        }
        
        return maxLength;
    }
};