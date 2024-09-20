#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        std::string rev_s = s; 
        std::reverse(rev_s.begin(), rev_s.end());

        std::string combined = s + "#" + rev_s;
        std::vector<int> lps(combined.size(), 0); 

        for (int i = 1; i < combined.size(); i++) {
            int len = lps[i - 1];
            
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            
            if (combined[i] == combined[len]) {
                len++;
            }
            
            lps[i] = len;
        }

        int longest_palindrome_prefix_len = lps.back();
    
        return rev_s.substr(0, s.size() - longest_palindrome_prefix_len) + s;      
    }
};