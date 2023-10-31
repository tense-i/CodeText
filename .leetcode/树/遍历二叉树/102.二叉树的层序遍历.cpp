/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
/*
class Solution
{
public:
    // int getDepth(TreeNode *root)
    // {
    //     if(root==nullptr)
    //         return 0;
    //     return max(getDepth(root->left), getDepth(root->right))+1;
    // }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> s;
        vector<vector<int>> ans;
        s.push(root);
        if (!root)
        {
            return {};
        }
        while (!s.empty())
        {
            ans.push_back(vector<int>());
            int sz = s.size();
            for (int i = 1; i <= sz; i++)
            {
                auto curr = s.front();
                s.pop();
                ans.back().push_back(curr->val);
                if (curr->left)
                    s.push(curr->left);
                if (curr->right)
                    s.push(curr->right);
            }
        }
        return ans;
    }
}; */
// @lc code=end
