/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
/* class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0, right = len - 1,mid=right-left;
        while (left <= right)
        {
            mid = (right - left) / 2 + left;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else{
                if(nums[mid]<target){
                    left = mid + 1;
                }
                else
                    return mid;
            }

        }
        return -1;
    }
}; */
// @lc code=end
