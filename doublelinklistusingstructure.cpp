#include<iostream>
using namespace std;
struct list{
    int info;
    struct list* prev;
    struct list* next;
};
struct list* start=NULL;
struct list* end=NULL;
void insertbeg(int value)
{
 struct list *ptr;
 ptr=new list;
 if(start==NULL)
 {
     ptr->info=value;
     start=ptr;
     end=ptr;
     ptr->prev=NULL;
     ptr->next=NULL;

 }
 else
 {
     ptr->info=value;
     ptr->next=start;
     start->prev=ptr;
     start=ptr;
     start->prev=NULL;
 }

}
void insertend(int value)
{
 struct list *ptr;
 ptr=new list;
 if(end==NULL)
 {
     ptr->info=value;
     ptr->next=NULL;
     ptr->prev=NULL;
     start=ptr;
     end=ptr;
 }
 else
 {
     ptr->info=value;
     ptr->next=NULL;
     end->next=ptr;
     ptr->prev=end;
     end=ptr;
 }
}
void deletebeg()
{struct list *temp;
 if(start==NULL)
 {
     cout<<"Underflow";

 }
 else if(start==end)
 {
     temp=start;
     start=NULL;
     end=NULL;
     delete temp;
 }
 else
 {
     temp=start;
     start=temp->next;
     start->prev=NULL;
     delete temp;
 }
}
void deleteend()
{
  struct list *temp;
  temp=start;
    if(start==NULL)
        cout<<"No data found"<<endl;
    else{
        if(start->next==NULL)
        {
            start=NULL;
            end=NULL;
            delete(temp);
        }
        else{
            temp=end;
            end=temp->prev;
            end->next=NULL;
            delete(temp);
        }
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
{   int num;
    while(1)
    {
        cout<<"Enter 1 to add data in the begining: \n";
        cout<<"Enter 2 to add data to the end: \n";
        cout<<"Enter 3 to delete at the beg\n";
        cout<<"Enter 4 to delete at the end\n";
        cout<<"Enter 5 to traverse\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cin>>num;
                insertbeg(num);
                break;
            case 2:
                cin>>num;
                insertend(num);
                break;
            case 3:
                deletebeg();
                break;
            case 4:
                deleteend();
                break;
            case 5:
                traverse();
                break;
            default:
                    return 0;
        }
    }
}

