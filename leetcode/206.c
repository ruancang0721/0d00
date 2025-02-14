/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    while(cur)
    {
      struct ListNode* temp=cur;
      cur = cur->next;
      temp->next=pre;
      pre=temp;
    }
    return pre;
}
//////////////////////////////////////////////////
struct ListNode* reverse(struct ListNode* pre,struct ListNode* cur)
 {
    if(!cur)
        return pre;
    struct ListNode* temp = cur->next;
    cur->next = pre;
    return reverse(cur,temp);
 }
struct ListNode* reverseList(struct ListNode* head) {
    return reverse(NULL,head);
}
