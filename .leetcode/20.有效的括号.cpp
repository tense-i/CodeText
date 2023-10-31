/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        stack<char> Sta;
        if (n % 2 != 0)
            return false;
        for (auto i : s)
        {
            if (i == '{' || i == '[' || i == '(')
                Sta.push(i);
            if (i == '}')
            {
                if (Sta.empty())
                    return false;
                else if (Sta.top() == '{')
                    Sta.pop();
                else
                    return false;
            }
            if (i == ']')
            {
                if (Sta.empty())
                    return false;
                else
                {
                    if (Sta.top() == '[')
                        Sta.pop();
                    else
                        return false;
                }
            }
            if (i == ')')
            {
                if (Sta.empty())
                    return false;
                else
                {
                    if (Sta.top() == '(')
                        Sta.pop();
                    else
                        return false;
                }
            }
        }
        if (Sta.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end
