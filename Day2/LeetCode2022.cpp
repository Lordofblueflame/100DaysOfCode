#include <vector>
#include <algorithm>
//my solution is slower and more coplicated
std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
    unsigned int space = m*n;

    if(space != original.size()) {
        return {};
    }

    int column = 0;
    int index = 0;
    std::vector<std::vector<int>> retVec;

    for(int i = 0; i < m; i++) { 
        index = column * n;
        std::vector<int> columnVec;

        for(int j = 0; j < n; j++) {
            columnVec.push_back(original[index+j]);   
        }

        column++;
        retVec.push_back(columnVec);
    }

    return retVec;
}
// I found this solution using copy from std:: to make efficient and elegant solution 
class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {};
        }

        std::vector<std::vector<int>> retVec(m, std::vector<int>(n)); // Initialize the 2D array with m rows and n columns.

        for (int i = 0; i < m; i++) {
            std::copy(  original.begin() + i * n,       // start with begin() iterator + 0 * columns
                        original.begin() + (i + 1) * n, // end with begin() iterator + (0+1) * columns 
                        retVec[i].begin());             // we put all those values between start and end as first layer of our new 2D Array
        }

        return retVec;
    }
};