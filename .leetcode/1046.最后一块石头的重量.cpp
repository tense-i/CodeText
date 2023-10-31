/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
/* class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        if(stones.size()==1)
            return stones[0];
        sort(stones.begin(), stones.end());
        for (int i = stones.size() - 1; i >= 0; i--)
        {
            if (stones[i] == stones[i - 1])
            {
                stones.pop_back();
                stones.pop_back();
            }
            else
            {
                int a = stones[i] - stones[i - 1];
                stones.pop_back();
                stones.pop_back();
                stones.push_back(a);
            }

            if (stones.size() == 1)
            {
                return stones[0];
            }
            if (stones.size() == 0)
            {
                return 0;
            }
            sort(stones.begin(), stones.end());
        }
        return 0;
    }
}; */
// @lc code=end
