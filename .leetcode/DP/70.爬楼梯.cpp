/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
/* class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n+10);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
}; */
// @lc code=end
