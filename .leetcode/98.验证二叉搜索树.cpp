/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
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
class Solution
{
public:
    bool solve(TreeNode *root, TreeNode *min, TreeNode *max)
    {
        if (root == NULL)
            return true;
        if (min != NULL && root->val <= min->val)
            return false;
        if (max != NULL && root->val >= max->val)
            return false;
        return solve(root->left, min, root) && solve(root->right, root, max);
    }
    bool isValidBST(TreeNode *root)
    {
        return solve(root, NULL, NULL);
    }
};
// @lc code=end
