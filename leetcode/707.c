


typedef struct x{
    int val;
    struct x * next;
    
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
   

   MyLinkedList* obj=(MyLinkedList*)malloc(sizeof(MyLinkedList));
   obj->val=0;
   obj->next=NULL;
   return obj;


}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(obj->next == NULL){
        return -1;
    }
        
    obj = obj->next;
    for(int i=0;i<index;i++){
        if(obj != NULL)
            obj = obj->next;
        else{
            return -1;
        }
            
    }
    if(obj == NULL){
        return -1;
    }
    return obj->val;



}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
      MyLinkedList* b=(MyLinkedList*)malloc(sizeof(MyLinkedList));
      b->val=val;
      b->next=obj->next;
      obj->next=b;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
        MyLinkedList* cur=obj;
        int i=0;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
  
    MyLinkedList* b=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    b->val=val;
    cur->next=b;
    b->next=NULL;
    
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
    MyLinkedList* b=obj;
    if(index<0)
    return;
   for(int i=0;i<index;i++)
   {
    if(b->next==NULL)
    {
        return;
    }
    else
    {
        b=b->next;
    }
   }
   MyLinkedList* temp=(MyLinkedList*)malloc(sizeof(MyLinkedList));
     temp->val=val;
     temp->next=b->next;
     b->next=temp;
     


}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* b=obj;

       for(int i=0;i<index;i++)
   {
    if(b->next==NULL)
    {
        return;
    }
    else
    {
        b=b->next;
    }
   }
   if(b->next==NULL)
   return;
    MyLinkedList* temp=b->next;
    
    b->next=b->next->next;
    free(temp);

}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* b=obj;
    while(b!=NULL)
    {
        MyLinkedList* temp=b;
        b=b->next;
        free(temp);
    }
    
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/