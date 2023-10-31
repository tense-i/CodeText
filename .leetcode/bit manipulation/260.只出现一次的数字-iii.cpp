/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
 class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int v = 0;
        for(auto i:nums){
            v ^= i;
        }
       int l = (v == INT_MIN ? v : v & (-v));
       // int l = v & (-v);
        int a = 0, b = 0;
        for(auto i:nums){
            if(l&i)
                a ^= i;
                else
                b ^= i;
        }
        vector<int> ans{a, b};
        return ans;
        /*  int n = nums.size();
         int v = 0;
         for (auto i : nums)
         {
             v ^= i;
         }
         int c = 0;
         for (; v; v >>= 1)
         {
             ++c;
         }
         int a = 0, b = 0;
         for (int i = 0; i < n; i++)
         {
             if ((nums[i] >> (c - 1)) & 1)
                 b ^= nums[i];
             else
                a ^= nums[i];
         }
         vector<int> ans{a, b};
         return ans;  */
    }
}; 
/* class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int n = nums.size(), xor_result = 0;
        for (int i : nums)
        {
            xor_result ^= i;
        }
        unsigned int diff_bit = xor_result & -xor_result; // get rightmost set bit
        int a = 0, b = 0;
        for (int i : nums)
        {
            if (i & diff_bit)
            {
                a ^= i;
            }
            else
            {
                b ^= i;
            }
        }
        vector<int> ans{a, b};
        return ans;
    }
}; */
// @lc code=end
