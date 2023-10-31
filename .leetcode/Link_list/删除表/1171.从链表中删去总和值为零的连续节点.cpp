/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
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
/* class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0,head);
        unordered_map<int, ListNode *> map;
        int sum=0;
        for (auto* curr = dummy; curr != NULL; curr = curr->next)
        {
            sum += curr->val;
            map[sum] = curr;
        }
        sum = 0;
        for (auto* curr = dummy; curr != NULL; curr = curr->next)
        {
            sum += curr->val;
            curr->next = map[sum]->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
}; */
// @lc code=end

