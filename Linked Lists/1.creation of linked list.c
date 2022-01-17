ALGORITHM :::
-------------------------------------------------------------------------------------------------------
1. Create a temporary node(temp) and assign the head node's address.

2. Print the data which present in the temp node.

3. After printing the data, move the temp pointer to the next node.

4. Do the above process until we reach the end.
---------------------------------------------------------------------------------------------------------
METHOD: 1 
without print function
#include<stdio.h>
#include<stdlib.h>

int main()
{
  //node structure
  struct node
  {
      int data;
      struct node *next;
  };

  //declaring nodes
  struct node *head,*middle,*last;

  //allocating memory for each node
  head   = malloc(sizeof(struct node));
  middle = malloc(sizeof(struct node));
  last   = malloc(sizeof(struct node));

  //assigning values to each node
  head->data   = 10;
  middle->data = 20;
  last->data   = 30;

  //connecting each nodes. head->middle->last
  head->next   = middle;
  middle->next = last;
  last->next   = NULL;

  //temp is a reference for head pointer.
  struct node *temp = head;

  //till the node becomes null, printing each nodes data
  while(temp != NULL)
  {
      printf("%d->",temp->data);
      temp = temp->next;
  }
  printf("NULL");

  return 0;
}

-------------------------------------------------------------------------------------------------------
    
    
    
 METHOD 2:USING PRINTLINKEDLIST FUNCTION
 
#include <stdio.h>
#include<stdlib.h>
//creating a node with self refrential structure(struct with pointer pointing to itself(here *next)
struct node
{
    int value;
    struct node *next;
    
};
//print llist values and traversing to next
void printll(struct node * p){
    while(p!=NULL)
     {
        printf("%d->",p->value);
       p= p->next;
     }
    }

int main()
{
    //intitialising the nodes will null values and creating a head pointer
    struct node *head;
    struct node*one=NULL;
    struct node*two=NULL;
    struct node*three=NULL;
    //assigning memory dynamically to the nodes using malloc
  one=malloc(sizeof(struct node));
  two=malloc(sizeof(struct node));
  three=malloc(sizeof(struct node));
//assigning values to nodes
 one->value=10;
 two->value=20;
 three->value=30;
 //connecting the nodes
 one->next=two;
 two->next=three;
 three->next=NULL;
 //pointing head pointer to first node and passing it to printll function
 head=one;
 printll(head);
 
    return 0;
}
