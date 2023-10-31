/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
/* class Solution
{
public:
    bool solve(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        else if (left == NULL || right == NULL)
            return false;
        else if (left->val != right->val)
            return false;
        else
            return solve(left->left, right->right) && solve(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return solve(root->left, root->right);
    }
}; */
// @lc code=end
