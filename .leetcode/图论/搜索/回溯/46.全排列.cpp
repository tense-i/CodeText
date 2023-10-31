/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
    void bfs(vector<int> &path, vector<bool> &used, vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                path.push_back(nums[i]);
                bfs(path, used, nums);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        used.resize(nums.size(), false);
        bfs(path, used, nums);
        return res;
    }
};
// @lc code=end
