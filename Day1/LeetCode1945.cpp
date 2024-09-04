#include <unordered_map>
#include <vector>
#include <string>

#include <numeric>
#include <algorithm>

class Solution {
private:
    std::unordered_map<char, int> alphabet;
    void initAlphabet() {
        for (char letter = 'a'; letter <= 'z'; ++letter) {
            alphabet[letter] = letter - 'a' + 1;
        }
    }

    std::vector<int> initStringToNumbers(const std::string& s) {
        std::vector<int> values;
        values.reserve(s.size()); 
        std::transform(s.begin(), s.end(), std::back_inserter(values),
                    [this](char c) {
                        return alphabet.at(c);
                    });
        return values;
    }

    void individualDigits(int number, std::vector<int>& transform) {
        if (number == 0) {
            transform.push_back(0); 
            return;
        }
        while (number > 0) {
            transform.push_back(number % 10); 
            number /= 10;                     
        }
    }

    int sumOfVector(const std::vector<int>& vec) {
        return std::accumulate(vec.begin(), vec.end(), 0);
    }
public:   
    //sum-of-digits-of-string-after-convert
    int getLucky(std::string s, int k) {
        initAlphabet();
        std::vector<int> values;
        values = initStringToNumbers(s);
        int sum = 0;

        for(int i  = 0 ; i < k ; i++ ) {
            std::vector<int> transform;

            for(const int& i : values) {
                individualDigits(i, transform); 
            }
            sum = sumOfVector(transform);
            values.clear();
            transform.clear();

            values.push_back(sum);
        }
        
        return sum;        
    }
};