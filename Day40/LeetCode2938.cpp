#include <string>

class Solution {
public:
    long long minimumSteps(std::string s) {
        std::size_t end = s.length();
        int onesAtEnd = 0;

        while(s[end] == '1') {
            ++onesAtEnd;
            end--;
            
        }
        if(onesAtEnd == s.length()-1 || onesAtEnd == s.length()) 
            return 0;


        std::size_t distance = s.length()-1 - onesAtEnd;
        long long steps = 0;
        for(std::size_t i = 0; i < s.length() - onesAtEnd ; ++i) {
            if(s[i] == '1') {
                steps += distance - i;
                --distance;
            }
        }

        return steps;
    }
};