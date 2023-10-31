/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int ans = 1;
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        int right = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > right)
            {
                ans++;
                right = points[i][1];
            }
        }
        return ans;
    }
};
// @lc code=end
