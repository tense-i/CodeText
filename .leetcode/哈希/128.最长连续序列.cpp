/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
// 将nums中的所有数都放到哈希表中；
// 然后遍历哈希表；
// 如果num - 1不存在，就从 num开始计算最长连续序列；
//如果存在则跳过，避免重复计算，且该结果也不是最大值。
 /* class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int ans = 0;
        unordered_set<int> s;
        for (auto i : nums)
            s.insert(i);
        for (auto i : nums)
        {
            if(s.count(i-1)==0){
                int curr = i + 1;
                int n = 1;
                while(s.count(curr)==1){
                    n++;
                    curr = curr + 1;
                }
                ans = max(ans, n);
            }
            
        }
        return ans;
    }
}; */
// @lc code=end
