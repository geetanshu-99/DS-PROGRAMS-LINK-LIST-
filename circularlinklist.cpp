#include<iostream>
using namespace std;
struct list{
    int info;
    struct list* prev;
    struct list* next;
};
struct list* start=NULL;
void insertbeg(int value)
{
 struct list *ptr;
 ptr=new list;
 if(start==NULL)
 {
     ptr->info=value;
    start=ptr;
     ptr->next=start;

 }
 else
 {  struct list *temp;
    temp=start;
    ptr->info=value;
     while(temp->next!=start)
     {
         temp=temp->next;
     }
     //cout<<"abc";
     temp->next=ptr;
     ptr->next=start;
     start=ptr;
   //  ptr->next=start;
    // start=ptr;
    // temp->next=start;
 }

}
void insertend(int value)
{
 struct list *ptr;
 ptr=new list;
 if(start==NULL)
 {
     ptr->info=value;
    start=ptr;
     ptr->next=start;

 }
 else{
    struct list *temp;
    temp=start;
    ptr->info=value;
    while(temp->next!=start)
        temp=temp->next;
    temp->next=ptr;
    ptr->next=start;
 }
}
void deleteend()
{
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else
    {
        struct list *temp,*temp1;
        temp=start;
        if(temp->next==start)
        {
            start=NULL;
            delete temp;
        }
        else
        {
            while(temp->next!=start)
            {
                temp1=temp;
                temp=temp->next;
            }
            temp1->next=start;
            delete temp;

        }
    }
}
void deletebeg()
{
  if(start==NULL)
  {
      cout<<"underflow";
  }
  else
  {
    struct list *temp,*temp1;
    temp=start;
    if(temp->next==start)
    {
        start=NULL;
        delete temp;

    }
    else{
            start=start->next;
            delete temp;

    }
  }
}
void traverse()
{struct list *temp;
    temp=start;
    while(temp->next!=start)
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

