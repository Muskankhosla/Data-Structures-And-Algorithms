/* ALGORITHM
1. Declare a head pointer and make it as NULL.

2. Create a new node with the given data.

3. Make the new node points to the head node.

4. Finally, make the new node as the head node.

*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
  

void addFirst(struct node **p, int val)
{
      //create a new node
      struct node *newNode = malloc(sizeof(struct node));
      newNode->data = val;

      newNode->next = *p;

      *p = newNode;
}

void printList(struct node *p)
{


    //iterate the entire linked list and print the data
    while(p != NULL)
    {
         printf("%d->", p->data);
         p = p->next;
    }
    printf("NULL\n");
}

int main()
{
     struct node *head = NULL;

     addFirst(&head,10);
     addFirst(&head,20);
     addFirst(&head,30);
     addFirst(&head,90);
     printList(head);

     return 0;
}
