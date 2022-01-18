
#include <iostream>

#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node * next;
    node(int data){
        val=data;
        next=NULL;
    }
};
node * reverse(node * p)
{ //here we will consider 3 pointers:prevptr,currptr,nextptr
   //prevptr pointing to null,currptr to head/start node
    node * prevptr=NULL;
    node * currptr=p;
    node * nextptr;
    //while loop till currptr!=null
    while(currptr!=NULL)
    {    
      //nextptr to next node of currptr
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
   return prevptr;
}

void addlast(node **p,int value)
{
         node * newNode=new node(value);
        newNode->val=value;
        newNode->next=NULL;
        if(*p==NULL)
        {
            *p=newNode;
        }
        else
        {
            node *temp=*p;
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
         cout<<p->val<<"->";
         p = p->next;
    }
    cout<<"NULL"<<endl;
  
}


int main()
{
   node *head = NULL;

     addlast(&head,10);
     addlast(&head,20);
     addlast(&head,30);
     addlast(&head,40);
     printList(head);
     node * newhead=reverse(head);
     printList(newhead);

    return 0;
}
