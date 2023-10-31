/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
/* class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int k, int n, int v)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = v + 1; i <= n; i++)
        {
            path.push_back(i);
            dfs(k, n, i);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        dfs(k, n, 0);
        return ans;
    }
}; */
// @lc code=end
