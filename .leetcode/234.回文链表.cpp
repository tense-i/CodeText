/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        ListNode *curr = head;
        while (curr)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        int n = v.size();
        if ( n == 0)
            return false;
        for (int i = 0; i < n;i++){
            if(v[i]!=v[n-i-1])
                return false;
        }
        return true;
    }
};
// @lc code=end
