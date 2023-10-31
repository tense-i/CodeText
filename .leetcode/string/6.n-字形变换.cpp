/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int len = s.size();
        int r = numRows;
        int t = 2 * r - 2;
        if(r==1||r>len)
            return s;
        string ans;
        int c = (t + len - 1) / t * (r - 1);
        vector<string> mat(r, string(c, 0));
        for (int i = 0, j = 0, k = 0; k < len; k++)
        {
            mat[i][j] = s[k];
            if (k % t < r - 1)
            {
                i++;
            }
            else
            {
                i--;
                j++;
            }
        }
        for (auto &i : mat)
        {
            for (auto j : i)
            {
                if (j)
                {
                    ans += j;
                }
            }
        }
        return ans;
    }
};
;
// @lc code=end
