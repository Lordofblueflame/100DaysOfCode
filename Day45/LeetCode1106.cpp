#include <vector>
#include <string>

class Solution {
public:
    bool parseAnd(std::string& expression) {
        auto subExpressions = splitExpressions(expression);
        for (auto& subExpr : subExpressions) {
            if (!parse(subExpr, subExpr[0])) {
                return false;
            }
        }
        return true;
    }

    bool parseOr(std::string& expression) {
        auto subExpressions = splitExpressions(expression);
        for (auto& subExpr : subExpressions) {
            if (parse(subExpr, subExpr[0])) {
                return true;
            }
        }
        return false;
    }

    bool parseNot(std::string& expression) {
        return !parse(expression, expression[0]);
    }

    bool parse(std::string& expression, char sign) {
        removeParanthesis(expression);
        
        if (sign == '|') {
            return parseOr(expression);
        } else if (sign == '&') {
            return parseAnd(expression);
        } else if (sign == '!') {
            return parseNot(expression);
        } else if (sign == 't') {
            return true;
        } else if (sign == 'f') {
            return false;
        }
        return false;
    }

    void removeParanthesis(std::string& expression) {
        if (expression.size() > 2) {
            expression = expression.substr(2, expression.size() - 3);
        } else {
            expression = "";
        }
    }

    std::vector<std::string> splitExpressions(const std::string& expression) {
        std::vector<std::string> result;
        int start = 0, bracketCount = 0;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '(') bracketCount++;
            if (expression[i] == ')') bracketCount--;
            if (expression[i] == ',' && bracketCount == 0) {
                result.push_back(expression.substr(start, i - start));
                start = i + 1;
            }
        }
        result.push_back(expression.substr(start));
        return result;
    }

    bool parseBoolExpr(string expression) {
        char sign = expression[0];
        return parse(expression,sign);
    }
};