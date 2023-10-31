/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int r = nums.size() - 1;
        int l = 0;
        int mid = (l + r) >> 1;
        while (l < r)
        {
            mid = (r + l) >> 1;
            if (target <= nums[mid])
                r = mid;
            else
                l = mid + 1;
        }
        if (target == nums[l])
            return l;
        return -1;
    }
};
// @lc code=end
