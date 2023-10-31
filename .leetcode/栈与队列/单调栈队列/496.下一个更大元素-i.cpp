/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n, -1);
        stack<int> s;
        unordered_map<int, int> ma;
        for (int i = 0; i < n;i++){
            ma[nums1[i]] = i;
        }
        s.push(0);
        for (int i = 1; i < m;i++){
            while(!s.empty()&&nums2[i]>nums2[s.top()]){
                if(ma.count(nums2[s.top()])>0){
                    int index = ma[nums2[s.top()]];
                    ans[index] = nums2[i];
                }
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end
