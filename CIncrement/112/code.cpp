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
    bool traverse(TreeNode *cNode, const int &targetSum, int currentSum) {
        if (cNode == nullptr) {
            return false;
        }
        currentSum += cNode->val;
        if (currentSum == targetSum) {
            if (cNode->left == nullptr && cNode->right == nullptr) {
                return true;
            }
        }
        return traverse(cNode->left, targetSum, currentSum) || traverse(cNode->right, targetSum, currentSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == targetSum) {
            if (root->left == nullptr && root->right == nullptr) {
                return true;
            }
        }
        return traverse(root->left, targetSum, root->val) || traverse(root->right, targetSum, root->val);
    }
};
