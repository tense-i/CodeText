/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> m;
    TreeNode *
    solve(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int poStart, int poEnd)
    {
        if (inStart > inEnd)
            return nullptr;
        int rootVal = postorder[poEnd];
        int index = m[rootVal];
        int LeftSize = index - inStart;
        TreeNode *root = new TreeNode(rootVal);
        root->left = solve(inorder, inStart, index - 1, postorder, poStart, poStart + LeftSize - 1);
        root->right = solve(inorder, index + 1, inEnd, postorder, LeftSize + poStart, poEnd - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
}; */
// @lc code=end
