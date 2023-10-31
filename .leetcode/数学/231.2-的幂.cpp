/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
/* class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int t = 1;
        if (n <= 0)
            return false;
        for (int i = 0; i < 31; i++)
        {

            if (t == n)
                return true;
            t <<= 1;
        }
        return false;
    }
}; */
// @lc code=end
