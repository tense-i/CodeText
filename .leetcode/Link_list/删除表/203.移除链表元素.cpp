/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                auto tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            }
            else
                curr = curr->next;
        }
        return dummy->next;
    }
};
// 递归
/* class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val) {
        if(head==nullptr)
            return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
}; */
// @lc code=end
