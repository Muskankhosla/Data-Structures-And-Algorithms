#include<iostream>
using namespace std;
class node{
   public:
   int val;
   node *next;
    node(int d){
      val=d;
      next= NULL;
    }
};

void insertatstart(struct node **p,int data)
{   
     node * NewNode= new node(data);
    if(*p==NULL)
    {
        *p=NewNode;
        return ;
    }
    NewNode->val=data;
    NewNode->next=*p;
    *p=NewNode;
    
}
void printll(struct node * p)
{
    while(p!=NULL)
    {
        cout<<p->val<<endl;
        p=p->next;
    }
}
int main()
{
    node * head=NULL;
    insertatstart(&head,1);
    insertatstart(&head,2);
    printll(head);
}
