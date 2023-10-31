/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
 class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = x, mid, ans = -1;
        while (left <= right)
        {
            mid = ((right - left) >> 1)+left;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid -1;
            }
        }
        return mid;
    }
};
class Solution
{
public:
    int mySqrt(int x)
    {
        long long l = 0, r = x;
        while (l < r)
        {
            long long mid = (l + r + 1) >> 1;
            if ((long long)mid * mid <= x)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

// @lc code=end
