// 1261. Find Elements in a Contaminated Binary Tree
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class FindElements {
private:
    TreeNode* _root;
public:
    FindElements(TreeNode* root) {
        if(root == nullptr) {
            return;
        }

        root->val = 0;  
        inOrderTraversal(root, 0);
        _root = root;
    }

void inOrderTraversal(TreeNode* node, int currentVal) {
        if (node != nullptr) {
            node->val = currentVal;
            inOrderTraversal(node->left, currentVal * 2 + 1);  
            inOrderTraversal(node->right, currentVal * 2 + 2);
        }
    }
    
    bool findNodeTraversal(TreeNode* node, int target) {
        if (node == nullptr) {
            return false;
        }
        
        if (node->val == target) {
            return true;  
        }

        return findNodeTraversal(node->left, target) || findNodeTraversal(node->right, target);
    }

    bool find(int target) {
        return findNodeTraversal(this->_root,target);
    }
};

/**
Your FindElements object will be instantiated and called as such:
FindElements* obj = new FindElements(root);
bool param_1 = obj->find(target);
 */