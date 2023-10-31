/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
/* class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int len = temperatures.size();
        vector<int> v(len, 0);
        stack<int> sta;
        for (int i = 0; i < len; i++)
        {
            while (!sta.empty() && temperatures[sta.top()] < temperatures[i])
            {
                int prev= sta.top();
                v[prev] = i - prev;
                //v.push_back(i-prev);
                sta.pop();
            }
            sta.push(i);
        }
        return v;
    }
}; */
// @lc code=end
