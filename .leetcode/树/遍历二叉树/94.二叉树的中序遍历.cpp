/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
   void solve(vector<int> &ans, TreeNode *root)
   {
       if (root == NULL)
           return;
       solve(ans, root->left);
       ans.push_back(root->val);
       solve(ans, root->right);
   }
   vector<int> inorderTraversal(TreeNode *root)
   {
       vector<int> ans;
       solve(ans, root);
       return ans;
   }
};  */
class Solution
{
public:
    void solve(vector<int> &ans, TreeNode *root)
    {
        if (root == NULL)
            return;
        solve(ans, root->left);
        ans.push_back(root->val);
        solve(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> ans;
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);

                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
// @lc code=end
