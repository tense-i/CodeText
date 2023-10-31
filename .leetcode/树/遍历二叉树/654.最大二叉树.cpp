/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *solve(int l, int r, vector<int> &nums)
    {
        if (l > r)
            return nullptr;
        int index = -1, maxval = INT_MIN;
        for (int i = l; i <= r; i++)
            if (maxval < nums[i])
            {
                index = i;
                maxval = nums[i];
            }
        TreeNode *root = new TreeNode(maxval);
        root->left = solve(l, index - 1, nums);
        root->right = solve(index + 1, r, nums);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return solve(0, nums.size() - 1, nums);
    }
};
// @lc code=end
