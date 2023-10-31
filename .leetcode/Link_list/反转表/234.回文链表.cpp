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
/* class Solution
{
public:
    vector<int> v1;
    bool isPalindrome(ListNode *head)
    {

        struct ListNode *curr = head;
        while (curr != nullptr)
        {
            v1.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        struct ListNode *pre = nullptr;
        while (curr != nullptr)
        {
            struct ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        int i = 0;
        while (pre != nullptr)
        {
            if (pre->val != v1[i++])
                return false;
            pre = pre->next;
        }
        return true;
    }
}; */
// @lc code=end
