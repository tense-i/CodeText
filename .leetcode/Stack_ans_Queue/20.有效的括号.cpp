/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
/* class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> v;
        if(s.size()%2!=0)
            return false; 
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                v.push(s[i]);
            if (s[i] == '}' || s[i] == ')' || s[i] == ']')
            {
                if (!v.empty())
                {
                    if (s[i] == ')')
                    {
                        if (v.top() != '(')
                            return false;
                        else
                            v.pop();
                    }
                    if (s[i] == '}')
                    {
                        if (v.top() != '{')
                            return false;
                        else
                            v.pop();
                    }
                    if (s[i] == ']')
                    {
                        if (v.top() != '[')
                            return false;
                        else
                            v.pop();
                    }
                }
                else
                    return false;
            }
        }
        if (v.empty())
            return true;
        else
            return false;
        return 0;
    }
}; */

// @lc code=end
