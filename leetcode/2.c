/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

int i=0;
struct ListNode*head =(struct ListNode*)malloc(sizeof(struct ListNode));
 struct ListNode*qaq=head;
while(l1||l2||i)
{
    if(l1)
    {
        i+=l1->val;
        l1=l1->next;
    }
    if(l2)
    {
        i+=l2->val;
        l2=l2->next;
    }
    qaq->next=malloc(sizeof(struct ListNode));
    qaq->next->val=i%10;
    qaq->next->next=NULL;
    qaq=qaq->next;
    i/=10;

}
return head->next;
}