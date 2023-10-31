/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *prev = nullptr;
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        queue<Node *> que;
        que.push(root);
        Node *prev = nullptr;
        while (!que.empty())
        {
            int sz = que.size();
            for (int i = 1; i <= sz; i++)
            {
                auto temp = que.front();
                que.pop();
                if (i <= sz - 1)
                {
                    temp->next = que.front();
                }
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }
        }
        return root;
    }
};
// @lc code=end
