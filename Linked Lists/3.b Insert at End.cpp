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

     return 0;
}
