#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct line{  
     int data;
     struct line *next;
}L;
void freelist(L*list)
{
    L*a=list->next;
    L*b;
    while(a!=NULL)
    {
        b=a->next;
        free(a);
        a=b;
    }
    list->next=NULL;

}
int listlen(L*list)
{
    L*a=list;
    int len=0;
    while(a!=NULL)
    {
        len++;
        a=a->next;
    }
    return len;
}
int deletenode(L*list,int pos)
{
    L*q=list;

    int i=0;
    while(i<pos-1)
    {
      q = q->next;
      i++;
      if(q==NULL)
      return 0;
    
    }
    if(q->next==NULL)
    return 0;
    L* p=q->next;
    q->next=p->next;
    free(p);
    return 1;
    
    q->next=q->next->next;
    
}
int intsertx(L*list,int pos,int data)
{
     int i=0;
     L*q =list;
     while(i<pos-1)
     {
        q=q->next;
        i++;
        if(q==NULL)
        {
            return 0;
        }
     }
     L*p=(L*)malloc(sizeof(L));
     p->data=data;
     p->next = q->next;
     q->next =p;
     return 1;


}
L* gettail(L* p)
{
    L*q=p;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    return q;
}
L* insert(L*tail,int data)
{
  L*q=(L*)malloc(sizeof(L));
  q->data=data;
  tail->next=q;
  q->next=NULL;
  return q;
}
void listbianli(L* head)
{
    L*p=head->next;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
        
    }
}
L* inserthead(L* head,int data)
{
    L* p = (L*)malloc(sizeof(L));
    p->data=data;
    p->next=head->next;
    head->next=p;
    return head;
}
L* initList()
{
    L*head = (L*)malloc(sizeof(L));
    head->data =0;
    head->next = NULL;
    return head;
}

int main()
{
    L* list= initList();
    inserthead(list,1);
    inserthead(list,2);
    inserthead(list,3);
    listbianli(list);

    return 0;
}