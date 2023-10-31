/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = head, *prev = dummy;
        while (curr && curr->next)
        {
            if (curr->val == curr->next->val)
            {
                while (curr->next&&curr->val == curr->next->val)
                    curr = curr->next;
                prev->next = curr->next;
            }
            else
            {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
}; */
// @lc code=end
