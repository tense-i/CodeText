/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/* class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *new_head;
    if (head == nullptr || head->next = nullptr)
      return head;
    new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
  }
}; */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 双指针法
/* struct ListNode* reverseList(struct ListNode* head){
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
}  */

// 递归；
/* struct ListNode *reverseList(struct ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  struct ListNode *newHead = reverseList(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
} */
/* struct ListNode *reverseList(struct ListNode *head)
{
  return reverse(NULL, head);
}
struct ListNode *reverse(struct ListNode *pre, struct ListNode *curr)
{

  if (!curr)
    return pre;
  struct ListNode *temp = curr->next;
  curr->next = pre;
  return reverse(curr, temp);
}
 */
/* struct ListNode* reverse(struct ListNode* pre, struct ListNode* cur) {
    if(!cur)
        return pre;
    struct ListNode* temp = cur->next;
    cur->next = pre;
    //将cur作为pre传入下一层
    //将temp作为cur传入下一层，改变其指针指向当前cur
    return reverse(cur, temp);
}

struct ListNode* reverseList(struct ListNode* head){
    return reverse(NULL, head);
} 
//@lc code=end
