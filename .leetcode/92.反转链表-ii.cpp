/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
ListNode *reverse(ListNode *head){
    ListNode *curr = head, *prev = nullptr;
    while(curr){
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *start = dummy, *end = nullptr;
        for (int i = 1; i < left; i++)
            start = start->next;
        ListNode *temp1 = start->next;
        // start = start->next;
        end = start->next;
        for (int i = left; i <right; i++)
        {
            end = end->next;
        }
        ListNode *temp2 = end->next;
        end->next = nullptr;
        start->next = reverse(start->next);
        temp1->next = temp2;
        return dummy->next;
    }
}; */
// @lc code=end
