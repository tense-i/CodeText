/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/* class Solution
{
public:
    int firstBadVersion(int n)
    {

        int left = 0, right = n, mid;
        while (left < right)
        {
            mid = left + ((right - left) >> 1);
            if (isBadversion(mid))
            {
                right = mid ;
            }
            else
                left = mid + 1;
        }
        return left;
    }
};

; */
// @lc code=end
