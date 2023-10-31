/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> deq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            while (!deq.empty() && nums[deq.back()] < nums[i])
                deq.pop_back();
            deq.push_back(i);
            if (i >= k - 1)
            {
                while (!deq.empty() && deq.front() < i - k + 1)
                {
                    deq.pop_front();
                }
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;
    }
};
// @lc code=end
