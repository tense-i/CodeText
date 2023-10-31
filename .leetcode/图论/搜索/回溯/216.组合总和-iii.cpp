/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
/* class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    long long sum = 0;
    void dfs(int k, int n, int v)
    {
        if (path.size() == k)
        {
            if (sum == n)
                ans.push_back(path);
            return;
        }
        for (int i = v + 1; i <= 9; i++)
        {
            path.push_back(i);
            sum += i;
            dfs(k, n, i);
            path.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(k, n, 0);
        return ans;
    }
}; */
// @lc code=end
