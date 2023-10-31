/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
/* class Solution { 
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {*/
        /*  stack<int> st;
         map<int, int> hash;
         for (int i = nums2.size() - 1; i >= 0;i--){
             int x = nums2[i];
            while(!st.empty()&&x>=st.top()){
                 st.pop();
             }
          hash[x]=st.empty()?-1:st.top();
          st.push(x);
         }
         vector<int> ans(nums1.size());
         for (int i = 0; i < nums1.size();i++){
             ans[i] = hash[nums1[i]];
         }
         return ans; */
  /*   }
}; */
// @lc code=end

