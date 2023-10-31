/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
/* class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    long long sum = 0;
    void dfs(vector<int> &candidates, int target, int v)
    {

        if (sum >= target)
        {
            if (sum == target)
                ans.push_back(path);
            return;
        }
        for (int i = v; i < candidates.size(); i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            // 不能出现前面的数比后面的数还大的情况即避免了重复数子 223 322 232
            dfs(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        if (candidates.size() == 0)
            return ans;
        dfs(candidates, target, 0);
        return ans;
    }
}; */
// @lc code=end
