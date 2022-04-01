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
    TreeNode *addNodes(const vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int middle = (left + right) / 2;
        TreeNode *nNode = new TreeNode(nums[middle]);
        nNode->left = addNodes(nums, left, middle - 1);
        nNode->right = addNodes(nums, middle + 1, right);
        return nNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 1) {
            TreeNode *n = new TreeNode(nums[0]);
            return n;
        }
        TreeNode *root = addNodes(nums, 0, nums.size() - 1);
        return root;
    }
};