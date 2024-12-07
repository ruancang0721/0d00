struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* cur = dummy;
    while(cur->next!=NULL&&cur->next->next!=NULL)
    {
        struct ListNode* temp = cur->next;
        cur->next = cur->next->next;
        temp->next=cur->next->next;
        cur->next->next = temp;
        cur=cur->next->next;


    }
   
    
    return dummy->next;
}
