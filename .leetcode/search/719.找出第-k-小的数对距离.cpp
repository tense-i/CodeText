/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 K 小的数对距离
 */

// @lc code=start
/* class Solution
{
public:
   int smallestDistancePair(vector<int> &nums, int k)
   {
       sort(nums.begin(), nums.end());
       vector<int>
v;
       for (int i = 0; i < nums.size(); i++)
       {
           for (int j = i + 1; j < nums.size(); j++)
           {
               v.push_back(abs(nums[i] - nums[j]));
           }
       }
       int ans(0);
       sort(v.begin(), v.end());
       for (int i = 0; i < v.size(); i++)
       {
           if (v[0] < v[i])
               ans++;
           if (ans == k)
               return v[i];
       }

       return 0;
   }
}; */
/* class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums.back() - nums.front();
        while (left <= right)
        {
            int mid = left+((right-left)>>1);
            int cnt = 0;
            for (int i = 0,j=0; i < n; i++)
            {
                while(nums[i]-nums[j]>mid)
                    j++;
                    cnt += i - j;
            }
            if (cnt >= k)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
}; */
// @lc code=end
