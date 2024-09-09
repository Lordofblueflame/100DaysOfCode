#include <iostream>
#include <vector>

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    std::vector<std::vector<int>> fillSpiralMatrix(int rows, int cols, ListNode* head) {
        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, -1));
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

        while (top <= bottom && left <= right && head != nullptr) {
            for (int i = left; i <= right && head != nullptr; ++i) {
                matrix[top][i] = head->val;
                head = head->next;
            }
            ++top;

            for (int i = top; i <= bottom && head != nullptr; ++i) {
                matrix[i][right] = head->val;
                head = head->next;
            }
            --right;

            if (top <= bottom) {
                for (int i = right; i >= left && head != nullptr; --i) {
                    matrix[bottom][i] = head->val;
                    head = head->next;
                }
                --bottom;
            }

            if (left <= right) {
                for (int i = bottom; i >= top && head != nullptr; --i) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                ++left;
            }
        }

        return matrix;
    }
};