/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> s;
        int n = nums.size();
        if (n < 3)
            return false;
        int third = INT_MIN;
        for (int i = n - 1; i >= 0;i--)
        {
            if (third > nums[i])
                return true;

            while(!s.empty()&&nums[i]>nums[s.top()]){
                third = nums[s.top()];
                s.pop();
            }
            s.push(i);
        }
        return false;
    }
};
// @lc code=end
