/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
/* class Solution {
public: */
// static bool cmp(const vector<vector<int> > &a,const vector<vector<int> > &b){
//     return a[1] < b[1];
// }
   /*  int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto &u, const auto &v)
             { return u[1] < v[1]; });
        int ans(1);//存在下，至少一个；
        int ed =points[0][1];
        int len = points.size();

        for (int i = 1; i < len; i++)
        {
            if (points[i][0] >ed)
            {
                ans++;
                ed = points[i][1];
            }
    }
    return ans;
    }
}; */
// @lc code=end

