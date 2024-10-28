#include <vector>

class Solution {
public:
    int maxHeightAfterRemoval[100001];
    int currentMaxHeight = 0;

    std::vector<int> treeQueries(TreeNode* root, std::vector<int>& queries) {
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;
        traverseRightToLeft(root, 0);

        int queryCount = queries.size();
        std::vector<int> queryResults(queryCount);
        for (int i = 0; i < queryCount; i++) {
            queryResults[i] = maxHeightAfterRemoval[queries[i]];
        }

        return queryResults;
    }

private:
    void traverseLeftToRight(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        maxHeightAfterRemoval[node->val] = currentMaxHeight;
        currentMaxHeight = std::max(currentMaxHeight, currentHeight);

        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    void traverseRightToLeft(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        maxHeightAfterRemoval[node->val] = 
            std::max(maxHeightAfterRemoval[node->val], currentMaxHeight);
        currentMaxHeight = std::max(currentHeight, currentMaxHeight);

        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};