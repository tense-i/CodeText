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
// 迭代；
/* class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *temp = dummy;
        while (temp->next != nullptr &&temp->next->next != nullptr)
        {
            ListNode *node1 = temp->next;
            ListNode *node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummy->next;
    }
}; */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *node1 = head;
        ListNode *node2 = head->next;

        while (node1 != nullptr && node1->next != nullptr)
        {
            auto tmp = node2->next;

            cur->next = node2;
            node2->next = node1;
            node1->next = tmp;

            cur = node1;
            node1 = cur->next;

            // Check if node1 is not nullptr before accessing node1->next
            if (node1 != nullptr)
            {
                node2 = node1->next;
            }
        }

        return dummy->next;
    }
};
// @lc code=end
