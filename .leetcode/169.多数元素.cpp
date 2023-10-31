/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution
{
public:
    int compare(vector<int> &nums, int target, int l, int r)
    {
        int cut = 0;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] == target)
                cut++;
        }
        return cut;
    }
    int solve(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return nums[l];
        }
        int mid = (r + l) >> 1;
        int lz = solve(nums, l, mid);
        int rz = solve(nums, mid + 1, r);
        if (compare(nums, lz, l, r) > (r - l+1) >> 1)
            return lz;
        if (compare(nums, rz, l, r) > (r - l+1) >> 1)
            return rz;
        return -1;
    }
    int majorityElement(vector<int> &nums)
    {
        return solve(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
