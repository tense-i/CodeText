/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
/* class Solution
{
private:
    int count_in_range(vector<int> &nums, int target, int lo, int hi)
    {
        int cut(0);
        for (int i = lo; i <= hi; i++)
        {
            if (nums[i] == target)
                cut++;
        }
        return cut;
    }
    int solve(vector<int> &nums, int lo, int hi)
    {
        //最小子问题的解；
        if (lo == hi)
            return nums[lo];
        int mid = (lo + hi) >> 1;
        //开始分治
        int left_majority = solve(nums, lo, mid);
        int right_majority = solve(nums, mid + 1, hi);
        //两部分至少一部分出现众数，分别考虑；
        if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) >> 1)
            return left_majority;
        if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) >> 1)
            return right_majority;
        return -1;
    }

public:
    int majorityElement(vector<int> &nums)
    {
        return solve(nums, 0, nums.size() - 1);
    }
}; */
// @lc code=end
