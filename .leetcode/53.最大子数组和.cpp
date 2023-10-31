/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0, ans = nums[0];
        for(auto i:nums){
            prev = max(prev + i, i);
            ans = max(ans, prev);
        }
        return ans;
    }
};
// @lc code=end

