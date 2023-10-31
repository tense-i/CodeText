/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

// 先进行中右左访问，再将结果反转；
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> ans;
        while (root || !s.empty())
        {
            while (root)
            {
                ans.push_back(root->val);
                s.push(root);
                root = root->right;
            }
            root = s.top();
            s.pop();
            root = root->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/* class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);
                ans.push_back(root->val);
                root = root->right;
            }
            root = s.top();
            s.pop();
            root = root->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}; */

// @lc code=end
