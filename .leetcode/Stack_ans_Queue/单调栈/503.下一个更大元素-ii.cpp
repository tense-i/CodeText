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
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> St;
        for (int i =( n*2-1); i >= 0; i--)
        {
            while (!St.empty() && nums[i%n] >= St.top())
            {
                St.pop();
            }
            ans[i%n]=(St.empty() ? -1 : St.top());
            St.push((nums[i % n]));
        }
        return ans;
    }
}; */
// @lc code=end
