/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
/* class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        s.push(0);
        for (int i = 1; i < n;i++){
            if(temperatures[i]<temperatures[s.top()]){
                s.push(i);
            }
            else{
                if (temperatures[i] ==temperatures[s.top()]){
                    s.push(i);
                }
                else{
                    while (!s.empty()&&temperatures[i] > temperatures[s.top()])
                    {
                        ans[s.top()]=(i - s.top());
                        s.pop();
                    }
                    s.push(i);
                }
            }
        }
        return ans;
        }
}; */

/* class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = 0; i < n;i++){
            while(!s.empty()&&temperatures[i]>temperatures[s.top()]){
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
}; */
// @lc code=end