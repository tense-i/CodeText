/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
/* class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> v;
        int t = 0;
        for (auto i : nums)
            t ^= i;
        t = (t==INT_MIN?t:(t & -t));
        int a=0, b=0;
        for (auto i : nums)
        {
            if (t & i)
                a ^= i;
            else
                b ^= i;
        }
       v.push_back(a);
        v.push_back(b);
        return v;
    }
}; */
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int t = 0;
        for (auto i : nums)
        {
            t ^= i;
        }
        int a = 0, b = 0;
        t = (t == INT_MIN ? t : (t & -t));
        for (auto i : nums)
        {
            if (i & t)
            {
                a ^= i;
            }
            else
                b ^= i;
        }
        vector<int> ans = {a, b};
        return ans;
    }
};
// @lc code=end
