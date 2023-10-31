/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    // 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
    // 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

    TreeNode *searchBST(TreeNode *root, int target)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        // 去左子树搜索
       if(root->val<target){
            return searchBST(root->right, target);
       }
       if(root->val>target)
       {
            return searchBST(root->left, target);
       }
       return root;
    }
};
// @lc code=end
 */