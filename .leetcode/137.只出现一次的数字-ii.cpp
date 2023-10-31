/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int total = 0;
            for (auto j : nums)
            {
                total += (j >> i) & 1;
            }
            if (total % 3 == 1)
            {

                ans |= (1<<i);
            }
        }
        return ans;
    }
};

// @lc code=end
