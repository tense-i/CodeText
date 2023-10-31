/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
/* class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        int t = 0;
        vector<char> v;
        string s;
        if (num < 0)
        {
            s += '-';
            num = -num;
        }
        while (num)
        {
            t = num % 7;
            v.push_back((t + '0'));
            num /= 7;
        }
        for (auto i = v.rbegin(); i != v.rend(); i++)
            s += *i;
        return s;
    }
}; */
// @lc code=end
