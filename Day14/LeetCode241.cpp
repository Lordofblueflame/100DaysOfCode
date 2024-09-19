#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int compute(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return 0;
    }

    vector<int> diffWaysToCompute(string expression, unordered_map<string, vector<int>>& memo) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        vector<int> result;
        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {

                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                vector<int> leftResults = diffWaysToCompute(left, memo);
                vector<int> rightResults = diffWaysToCompute(right, memo);
                
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        result.push_back(compute(l, r, c));
                    }
                }
            }
        }
        
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        memo[expression] = result;
        return result;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        return diffWaysToCompute(expression, memo);
    }
};