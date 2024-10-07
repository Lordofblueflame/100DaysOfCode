#include <string>

class Solution {
public:
    int minLength(std::string s) {
        int count = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            s[count] = s[i];
            
            if (count > 0 && 
                ((s[count - 1] == 'A' && s[count] == 'B') || 
                 (s[count - 1] == 'C' && s[count] == 'D'))) {
                count -= 2;
            }
            
            ++count;
        }
        
        return count;
    }

};