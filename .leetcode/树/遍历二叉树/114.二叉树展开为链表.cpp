/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        flatten(root->left);
        flatten(root->right);

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = nullptr;
        root->right = left;
        // 遍历拼接后的树
        TreeNode *p = root;
        while (p->right)
        {
            p = p->right;
        }
        // 将原来的右子树接到现在的右子树的末端
        p->right = right;
    }
};
// @lc code=end
