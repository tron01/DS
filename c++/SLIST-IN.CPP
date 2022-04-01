/*node insertion*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
using namespace std;
struct node
   {
    int info;
    struct node *next;
    };
    
    
 typedef struct node NODE;
 class llist
     {
      int value;
      NODE *head,*nnode;
      public:

	    void node_creation();
	    void insert_first();
	    void insert_last();
	    void insert_pos();
	    void list_display();

      llist()
       {
	head=NULL;
       }
      };
      
 int main()
    { 
    	system("cls");
      llist l1;
      int ch;
      do
      {
      cout<<"1. Insert as first node"<<endl;
      cout<<"2. Insert as a last node "<<endl;
      cout<<"3. Insert in a position"<<endl;
      cout<<"4. Display the linked list contents"<<endl;
      cout<<"5. Exit"<<endl;
      cin>>ch;
      switch(ch)
	{
	case 1: l1.node_creation();
		l1.insert_first();
		break;
	case 2: l1.node_creation();
		l1.insert_last();
		break;
	case 3: l1.node_creation();
		l1.insert_pos();
		break;
	case 4: l1.list_display();
		break;
	}

     }while(ch!=5);
    getch();
    }
 void llist::node_creation()
     {
       int num;
       nnode=new NODE;
       cout<<"Enter node information"<<endl;
       cin>>num;
       nnode->info=num;
       nnode->next=NULL;
     }
 void llist::insert_first()
     {
       if(head==NULL)
	  head=nnode;
       else
	{
	 nnode->next=head;
	 head=nnode;
	}
      }

 void llist::insert_last()
     {
      NODE *temp;
      if(head==NULL)
	 head=nnode;
      else
       {
	temp=head;
	while(temp->next!=NULL)
	    temp=temp->next;
	temp->next=nnode;
       }
     }
  void llist::insert_pos()
     {
      int pos,i=1;
      NODE *prev,*temp;
      cout<<"enter insertion position"<<endl;
      cin>>pos;
      temp=head;
      while(i<pos)
       {
	prev=temp;
	temp=temp->next;
	++i;
       }
       nnode->next=prev->next;
       prev->next=nnode;
    }
   void llist::list_display()
     {
      NODE *temp;
      cout<<"The linked list Contents are "<<endl;
      temp=head;
      while(temp!=NULL)
	{
	  cout<<temp->info<<endl;
	  temp=temp->next;
	}
      getch();
     }
