//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool traverseTree(TreeNode* node, ListNode* movHead) {
        if (movHead == nullptr) {
            return true;
        }
        if (node == nullptr) {
            return false;
        }

        if (node->val != movHead->val) {
            return false;
        }

        return traverseTree(node->left, movHead->next) || traverseTree(node->right, movHead->next);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) {
            return false;
        }

        return traverseTree(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};