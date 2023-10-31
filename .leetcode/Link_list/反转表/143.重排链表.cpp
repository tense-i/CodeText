/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode *head)
    {

        ListNode *curr = head;
        int len = 0;
        while (curr)
        {
            curr = curr->next;
            len++;
        }
        curr = head;
        ListNode *prev = nullptr;
        for (int i = 1; i <= len / 2; i++)
        {
            curr = curr->next;
        }
        ListNode *new_head = curr->next;
        curr->next = nullptr;
        new_head = reverse(new_head);
        curr = head;
        while (new_head)
        {
            ListNode *temp = curr->next, *temp2 = new_head->next;
            curr->next = new_head;
            new_head->next = temp;
            new_head = temp2;
            curr = temp;
        }
    }
    ListNode *reverse(ListNode *head)
    {
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        while (curr)
        {
            struct ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}; */
// @lc code=end
