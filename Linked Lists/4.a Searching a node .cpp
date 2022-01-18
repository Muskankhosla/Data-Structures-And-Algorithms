Algorithm
1. Iterate the linked list using a loop.

2. If any node has the given key value, return 1.

3. If the program execution comes out of the loop (the given key is not present in the linked list), return -1.

#include<iostream>
using namespace std;

class node
{ 
    public:
  int val;
  node * next;
  node(int data)
  {
      val=data;
      next=NULL;
  }
};
 bool search(node *p,int key)
 {
     node*temp=p;
     while(temp!=NULL)
     {
         if(temp->val==key)
         {
             return true;
         }
         temp=temp->next;
     }return false;
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
     int x;
     cin>>x;
     if(search(head,x)==true)
     {
         cout<<"yes";
     }
     else
     {
           cout<<"NOT PRESENT!!!";
     }

     return 0;
}
