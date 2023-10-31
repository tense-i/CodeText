#include <bits/stdc++.h>
using namespace std;


bool is_complete_bt(TreeNode *root)
{
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    auto curr = q.front();
    if (curr)
    {
      q.push(curr->left);
      q.push(curr->right);
    }
    else
      while (!q.empty())
      {
        //空节点之后还有节点，即为非完全；
        auto temp = q.front();
        if (temp)
          return false;
      }
  }
  return true;
}