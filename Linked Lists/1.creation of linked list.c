
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
