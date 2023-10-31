/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
/*  class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode *start = dummy;
        ListNode *end = dummy;
        while (true)
        {
            for (int i = 0; i < k && end != nullptr; i++)
            {
                end = end->next;
            }
            if (end == nullptr)
                break;
            ListNode *endNext = end->next;
            ListNode *startNext = start->next;
            end->next = nullptr;
            start->next = reverse(start->next);
            startNext->next = endNext;
            start = end = startNext;
        }
        return dummy->next;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};  */
/* #include <bits/stdc++.h>
using namespace std;
typedef struct ListNode
{
    int val;
    ListNode *next;
} ListNode; */
// 法一
 /* class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *start = dummyhead, *end = dummyhead;
        while (true)
        {
            for (int i = 0; i < k && end != nullptr; i++)
            {
                end = end->next;
            }
            if (end == nullptr)
                break;
            ListNode *startNext = start->next, *endNext = end->next;
            end->next = nullptr; // 断开
            start->next = reverse(start->next);
            startNext->next = endNext; // 拼接；
            start = end = startNext;
        }
        return dummyhead->next;
    }
    struct ListNode *reverse(struct ListNode *head)
    {
        struct ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr)`
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};  */
/*
int
main()
{

    return 0;
} */
// @lc code=end

 class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *start = dummyhead, *end = dummyhead;
        while (true)
        {
            for (int i = 0; i < k && end != nullptr; i++)
            {
                end = end->next;
            }
            if (end == nullptr)
                break;
            ListNode *new_end = start->next, *next_new_head = end->next;//start->next指向不变，反转后任指向原链表的头，反转后原头成为了现尾部，则new_end为反转后的尾节点，next_new_head一样；
            end->next = nullptr; // 断开
            start->next = reverse(start->next);//拼头
            startNext->next = endNext; // 拼尾；
            start = end = startNext;//指向反转的尾巴，相当于dummy，重循环；
        }
        return dummyhead->next;
    }
    struct ListNode *reverse(struct ListNode *head)
    {
        struct ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
}; 