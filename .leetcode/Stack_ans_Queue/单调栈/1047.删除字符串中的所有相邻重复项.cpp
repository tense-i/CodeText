/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
/* class Solution
{
public:
    string removeDuplicates(string s)
    {
        string Sta;
        for (char i : s)
        {
            if (!Sta.empty() && Sta.back()==i)
                Sta.pop_back();
            else
                Sta.push_back(i);
        }
        return Sta;
    }
}; */
// @lc code=end
