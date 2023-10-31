/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution
{
public:
    void solve(vector<int> &nums, vector<int> &temp, int l, int r)
    {
        if (l >= r)
            return;

        int mid = (l + r) >> 1;
        solve(nums, temp, l, mid);
        solve(nums, temp, mid + 1, r);
        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
                temp[k++] = nums[j++];
        }
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= r)
            temp[k++] = nums[j++];
        for (int i = 0; i < r - l + 1; i++)
            nums[i + l] = temp[i];
    }
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> temp(nums.size());
        solve(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end
