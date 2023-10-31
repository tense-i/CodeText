/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        if (g.size() == 0 || s.size() == 0)
            return 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int j = s.size() - 1;
        int ans = 0;
        for (int i = g.size() - 1; i >= 0; i--)
        {
            if (j >= 0 && g[i] <= s[j])
            {
                ans++, j--;
            }
        }
        return ans;
    }
};
// @lc code=end
