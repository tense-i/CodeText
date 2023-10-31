/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
/* class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n, -1);
        // s.push(0);
        for (int i = 0; i < n * 2; i++)
        {
            while (!s.empty() && nums[i % n] > nums[s.top()])
            {
                ans[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }
        return ans;
    }
}; */
// @lc code=end
