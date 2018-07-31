#include<iostream>
#include<stdlib.h>
using namespace std;
class list{
public:
    int info;
    list *next;
};
class link_list:public list
{public:
   list *start;
    void insert_beg(int);
    void insert_end(int);
    void delete_beg();
    void delete_end();

    void traverse();

};
void link_list::insert_beg(int value)
{
    list *ptr;
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
void link_list::insert_end(int value)
{
 list *ptr;

    ptr=new list;
    if(start==NULL)
    {
        ptr->info=value;
        ptr->next=NULL;
        start=ptr;
    }
    eelse
    {
        ptr->info=value;
        ptr->next=NULL;
        list *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=ptr;
        ptr->next=NULL;


    }

   // cout<<ptr->info;

}
void link_list::delete_beg()
{ list *temp;
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
void link_list::delete_end()
{list *temp,*temp1;
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
    }

}
void link_list::traverse()
{list *temp;
temp=start;
    while(temp->next!=NULL)
    {
        cout<<temp->info;
    }
    cout<<temp->info;
}
int main()
{  int ch;
int num;
link_list li;
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
                li.insert_beg(num);
                break;
            case 2:
                 cin>>num;
                li.insert_end(num);
                break;
            case 3:
                li.delete_beg();
                break;
            case 4:
                li.delete_end();
                break;
            case 5:
                li.traverse();
                break;
            default:
                cout<<"wrong choice"<<endl;
                exit(0);
        }
    }
}
