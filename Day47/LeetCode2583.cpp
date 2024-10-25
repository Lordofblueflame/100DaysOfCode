struct TreeNode {
     long long val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> min_heap;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            long long level_size = q.size();
            long long level_sum = 0;

            for (long long i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                level_sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (min_heap.size() < k) {
                min_heap.push(level_sum);
            } else if (level_sum > min_heap.top()) {
                min_heap.pop();
                min_heap.push(level_sum);
            }
        }

        return min_heap.size() == k ? min_heap.top() : -1;
    }
};