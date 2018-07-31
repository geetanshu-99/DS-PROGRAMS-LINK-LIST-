#include<iostream>
#include<stdlib.h>
using namespace std;
struct list
{
    int info;
    struct list *next;
};struct list *start,*curr,*prev,*forw;
void insertion(int value)
{
    struct list *ptr;
    ptr=new list;
    if(start==NULL)
    {
        ptr->info=value;
        ptr->next=NULL;
        start=ptr;
    }
    else
    {
        ptr->info=value;
        ptr->next=NULL;
        list *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=ptr;
        ptr->next=NULL;


    }


}
void sorting()
{struct list *temp,*temp1,*prev;
 temp=start;
 while(temp!=NULL)
 {
     temp1=start->next;
     prev=start;
     while(temp1!=NULL)
     {
         if(prev->info>temp1->info)
         {
             int a=temp1->info;
             temp1->info=prev->info;
             prev->info=a;
         }
         prev=temp1;
         temp1=temp1->next;
     }
     temp=temp->next;
 }

}
void duplicate()
{
    struct list *temp,*prev,*temp1,*temp2;
    for(temp=start;temp!=NULL;temp=temp->next)
    {
        prev=temp;
        for(temp1=temp->next;temp1!=NULL;)
        {   if(temp->info==temp1->info){
            prev->next=temp1->next;
            temp2=temp1;
            temp1=temp1->next;
            delete temp2;
        }
        else{
            prev=temp1;
            temp1=temp1->next;
        }
        }
    }

}
void reversee()
{
    curr=start;
    while(curr!=NULL)
    {
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    start=prev;

}
void traverse()
{struct list *temp;
 temp=start;
 while(temp->next!=NULL)
 {
     cout<<temp->info;
     temp=temp->next;
 }
    cout<<temp->info;
}
int main()
{
    int num;
    int ch;
    while(1)
    {   cout<<"enter 1 for insertion"<<endl;
        cout<<"enter 2 for sorting"<<endl;
        cout<<"enter 3 duplicate"<<endl;
        cout<<"enter 4 for reverse"<<endl;
        cout<<"enter 5 for traverse"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cin>>num;
                insertion(num);
                break;
            case 2:
                 sorting();
                break;
            case 3:
                duplicate();
                break;
            case 4:
                reversee();
                break;
            case 5:
                traverse();
                break;
            default:
                cout<<"wrong choice"<<endl;
                exit(0);
        }
    }
}
