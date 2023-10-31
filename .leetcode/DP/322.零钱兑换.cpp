/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    vector<int> m;
    // int dp(vector<int> &coins, int amount);
  
    int dp(vector<int> &coins, int amount)
    {
        int res = INT_MAX;
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (m[amount] != -666)
            return m[amount];
        for (auto coin : coins)
        {
            int subpro = dp(coins, amount - coin);
            if(subpro==-1)
                continue;
            res = min(res, subpro + 1);
        }
        m[amount] = res == INT_MAX ? -1 : res;
        return m[amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        m.resize(amount + 1, -666);
        // 题目要求的最终结果是 dp(amount)
        return dp(coins, amount);
    }
};
// @lc code=end
