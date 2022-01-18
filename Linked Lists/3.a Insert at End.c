Algorithm
1. Declare head pointer and make it as NULL.
2. Create a new node with the given data. And make the new node => next as NULL.
    (Because the new node is going to be the last node.)
3. If the head node is NULL (Empty Linked List),
 make the new node as the head.
4. If the head node is not null, (Linked list already has some elements),
find the last node.make the last node => next as the new node.

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
