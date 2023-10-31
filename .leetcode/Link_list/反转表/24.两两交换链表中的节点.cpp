/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
/* class Solution{
    public:
    ListNode *swapPairs(ListNode *head){
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *curr = dummyhead;
        while(curr->next!=nullptr&&curr->next->next!=nullptr){
            ListNode *node1 = curr->next;
            ListNode *node2 = curr->next->next;
            curr->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            curr = node1;
        }
        return dummyhead->next;
    }
}; */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        struct ListNode *pre = nullptr;
        struct ListNode *curr = nullptr;
        struct ListNode *p = nullptr;
        struct ListNode *newhead = nullptr;
        pre = head;
        curr = pre->next;
        newhead = curr;
        while (pre->next != nullptr)
        {
            p = curr->next->next;
            q = curr->next;
            curr->next = pre;
            pre->next = p;
            pre = q;
            curr = p;
        }

        // 法一。迭代
        struct ListNode *dummyhead = nullptr, *curr = nullptr, *ptemp = nullptr;
        dummyhead = new ListNode(0);
        // dummyhead = head;
        dummyhead->next = head;
        curr = dummyhead;
        while (curr->next != nullptr && curr->next->next != nullptr)
        {

            struct ListNode *node1 = nullptr, *node2 = nullptr;
            node1 = curr->next;
            node2 = curr->next->next;
            curr->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            curr = node1;
        }
        return dummyhead->next;
        // 法二。递归
        /* if(head==nullptr||head->next==nullptr)
            return head;
        auto newhead = head->next;
        head->next = swapPairs(newhead->next);
        newhead->next = head;
        return newhead;
    } 
//};
// @lc code=end
