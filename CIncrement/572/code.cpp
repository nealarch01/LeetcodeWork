/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // check the entire tree
    bool checkFullTree(TreeNode *root, TreeNode *subRoot) {
        if ((root == nullptr) ^ (subRoot == nullptr)) {
            return false;
        }
        if ((root == nullptr) && (subRoot == nullptr)) {
            return true;
        }
        if (root->val == subRoot->val) {
            return (checkFullTree(root->left, subRoot->left) && checkFullTree(root->right, subRoot->right));
        }
        return false;
    }
    // find a node in which the values of root and subroot equals each other
    bool match(TreeNode *root, TreeNode* subRoot) {
        if ((root == nullptr) ^ (subRoot == nullptr)) {
            return false;
        }
        if (root->val == subRoot->val) {
            if (checkFullTree(root, subRoot)) {
                return true;
            }
        }
        if (match(root->left, subRoot) || match(root->right, subRoot)) {
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if ((root == nullptr) ^ (subRoot == nullptr)) {
            return false;
        }
        return match(root, subRoot);
    }
};