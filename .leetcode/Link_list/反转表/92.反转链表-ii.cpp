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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    { */
        


        /* ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *curr = head;
        ListNode *start = dummyhead;
        ListNode *end = head;
        int i = left;
        while(--i){
            curr = curr->next;
            start = start->next;
        }
       i = right - left;
        while(i--){
            curr = curr->next;
        }
        ListNode  *temp1 = curr->next, *temp2 = start->next;
        curr->next = nullptr;
        //end = curr;
        start->next = reverse(start->next);
        temp2->next = temp1;
        return dummyhead->next;
    }   
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr, *curr = head;
        while (curr!=nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    } */
//};
// @lc code=end
