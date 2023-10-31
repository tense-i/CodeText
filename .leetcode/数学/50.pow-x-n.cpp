/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double quickPow(double x, long long n)
    {
        double ans = 1.0;
        for (; n; n >>= 1)
        {
            if (n & 1)
                ans *= x;
            x *= x;
        }
        return ans;
    }
    double myPow(double x, int n)
    {
        long long N = n;
        if (x == 1.00000)
            return x;
        if (n >= 0)
            return quickPow(x, N);
        else
            return 1.0 / quickPow(x, -N);
    }
};
// @lc code=end
