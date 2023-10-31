/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q || root == NULL)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)
            return root;
        if (left != NULL && right == NULL)
            return left;
        else
        {
            if (left == NULL && right != NULL)
                return right;
            else
                return NULL;
        }
        return NULL;
    }
};
/* class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == q || root == p || root == NULL)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)
            return root;

        if (left == NULL && right != NULL)
            return right;
        else if (left != NULL && right == NULL)
            return left;
        else
        { //  (left == NULL && right == NULL)
            return NULL;
        }
    }
}; */
// @lc code=end
