/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start

//选择边界问题

// 选择右边界，mid=r+l+1>>1;过不了，有少量的数据过不了；
/* class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
         int l = 0, r = nums.size() - 1, mid;
        if (target > nums[r])
            return r+1;
        if (target < nums[0])
            return 0;
        while (l < r)
        {
            mid = (l + r+1) >> 1;
            if (target >= nums[mid])
                l = mid;
            else
                r = mid - 1;
        }
        if (nums[l] == target)
            return l;
        return l;
    }
};
 */

//选择左边界就能AC，为什么？
/* class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
            int len = nums.size();
            // 特殊判断
            if (nums[len - 1] < target)
            {
                return len;
            }
            // 程序走到这里一定有 nums[len - 1] >= target，插入位置在区间 [0..len - 1]
            int left = 0;
            int right = len - 1;
            // 在区间 nums[left..right] 里查找第 1 个大于等于 target 的元素的下标
            while (left < right)
            {
                int mid = (left + right) >> 1;
                // int mid = left + (right - left) / 2;
                if (nums[mid] >= target)
                {
                    // 下一轮搜索的区间是 [mid + 1..right]
                    right = mid;
                }
                else
                {
                    // 下一轮搜索的区间是 [left..mid]
                    // right = mid - 1;
                    left = mid + 1;
                }
            }
            return left;
        }
}; */
        // @lc code=end
