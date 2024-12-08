struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* left=dummy;
    struct ListNode* right=head;
    
    for(int i=0;i<n;i++)
    {
        right=right->next;
    }
    while(right!=NULL)
    {
        left=left->next;
        right=right->next;
    }
    struct ListNode* temp=left->next;
    left->next=left->next->next;
    head = dummy->next;
    free(temp);
    free(dummy);
    return head;
}
