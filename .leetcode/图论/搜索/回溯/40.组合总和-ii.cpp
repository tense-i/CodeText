/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    long long sum = 0;
    vector<bool> vis;
    void dfs(vector<int> &candidates, int target, int v)
    {

        if (target == sum)
        {
            ans.push_back(path);
            return;
        }

        for (int i = v; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            if (i > 0 && candidates[i] == candidates[i - 1] && vis[i - 1] == false)
                continue;
            sum += candidates[i];
            vis[i] = true;
            path.push_back(candidates[i]);
            dfs(candidates, target, i + 1);
            sum -= candidates[i];
            vis[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vis.resize(candidates.size() + 1, false);

        dfs(candidates, target, 0);

        return ans;
    }
};
// @lc code=end
