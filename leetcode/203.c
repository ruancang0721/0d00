struct ListNode* removeElements(struct ListNode* head, int val) {
struct ListNode* dummyhead=(struct ListNode*)malloc(sizeof(struct ListNode));
dummyhead->next=head;

struct ListNode* cur= dummyhead;
while(cur->next!=NULL)
{
    if(cur->next->val==val)
    {
        struct ListNode* temp=cur->next;
       cur->next = cur->next->next;
       free(temp);
    }
    else
    {
        cur=cur->next;
    }
    
}
head=dummyhead->next;
return head;
}