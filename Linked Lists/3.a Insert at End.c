#include<stdio.h>
#include<stdlib.h>
struct node
{
  int val;
  struct node * next;
};

void addlast(struct node **p,int value)
{
        struct node * newNode=malloc(sizeof(struct node));
        newNode->val=value;
        newNode->next=NULL;
        if(*p==NULL)
        {
            *p=newNode;
        }
        else
        {
            struct node *temp=*p;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    
}
void printList(struct node *p)
{


    //iterate the entire linked list and print the data
    while(p != NULL)
    {
         printf("%d->", p->val);
         p = p->next;
    }
    printf("NULL\n");
}

int main()
{
     struct node *head = NULL;

     addlast(&head,10);
     addlast(&head,20);
     addlast(&head,30);
     addlast(&head,40);
     printList(head);

     return 0;
}
