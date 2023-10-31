/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    void solve(TreeNode *root, int &k, int &ans, int &res)
    {
        if (root == NULL)
            return ;
        solve(root->left, k, ans, res);
        res++;
        if(res==k){
            ans = root->val;
            return ;
        }
        solve(root->right, k, ans, res);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans(0), res(0);
        solve(root, k, ans, res);
        return ans;
    }
};
// @lc code=end
