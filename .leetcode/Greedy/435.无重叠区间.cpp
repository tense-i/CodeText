/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= right)
            {
                ans++;
                right = intervals[i][1];
            }
            else
            {
                res++; // 忽略区间的个数（删除区间的个数）；
            }
        }
        // return n - ans;
        return res;
    }
};
// @lc code=end
