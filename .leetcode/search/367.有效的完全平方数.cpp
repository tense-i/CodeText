/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long long left = 1, right = num, mid;
        long long ans = 1;
        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (mid * mid <= num)
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        if (ans * ans == num)
            return true;
        else
            false;
        return false;
    }
};
// @lc code=end
