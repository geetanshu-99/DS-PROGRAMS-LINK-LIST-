#include<iostream>
#include<stdlib.h>
using namespace std;
struct list
{
    int info;
    struct list *next;
};
struct list *start;
void insert_beg(int value)
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
        ptr->next=start;
        start=ptr;
    }

}
void insert_end(int value)
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
void delete_end()
{struct list *temp,*temp1;
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else if(start->next==NULL)
    {
        temp=start;
        start=NULL;
        delete temp;
    }
    else{temp=start;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        delete temp;
    }

}
void delete_beg()
{struct list *temp,*temp1;
    if(start==NULL)
 {

     cout<<"underflow";
 }
 else
 {
     temp=start;
     start=temp->next;
     delete temp;
     //temp=temp1;

 }

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
    {   cout<<"enter 1 for insertion at begining"<<endl;
        cout<<"enter 2 for insertion at end"<<endl;
        cout<<"enter 3 for delete at begining"<<endl;
        cout<<"enter 4 for delete at end"<<endl;
        cout<<"enter 5 for traverse"<<endl;

        cin>>ch;
        switch(ch)
        {
            case 1:
                cin>>num;
                insert_beg(num);
                break;
            case 2:
                 cin>>num;
                insert_end(num);
                break;
            case 3:
                delete_beg();
                break;
            case 4:
                delete_end();
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
