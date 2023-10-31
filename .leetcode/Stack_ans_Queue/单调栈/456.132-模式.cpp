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
        int third = INT_MIN;
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < third)
                return true;
            while (!s.empty() && nums[i] > s.top())
            {
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
        /* int n = nums.size();
        int k = 0;
        for (int i = 1; i <n;i++){
            k = nums[i] - nums[i - 1];
        }
        if(k>0)
            return false;
            stack<int> s;
        for (int i = n - 1; i >= 0 && i - 1 >= 0; i--)
        {
            while (!s.empty() && (nums[i] <= s.top() || nums[i] <= nums[i - 1]))
                s.pop();
            s.push(nums[i]);
        }
        if (s.empty())
            return false;
        else
        {
            if (s.top() == nums[0])
                return false;
            else
                return true;
        }
        return false;
    } */
    }
};

// @lc code=end
