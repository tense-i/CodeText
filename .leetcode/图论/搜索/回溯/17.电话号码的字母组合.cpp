/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
/* class Solution
{
public:
    vector<string> ans;
    string path;
    vector<string> str{" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string t;
    void dfs(string &digits, int index)
    {
        if (digits.size() == index)
        {
            ans.push_back(path);
            return;
        }
        int k = digits[index] - '0';
        string s = str[k];

        for (int i = 0; i < s.size(); i++)
        {

            path.push_back(s[i]);
            dfs(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return ans;
        dfs(digits, 0);
        return ans;
    }
}; */
// @lc code=end
