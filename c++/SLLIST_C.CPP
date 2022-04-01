/* single linkedlist creation*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
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
	 NODE *head, *prev;
	  public:
	    void creation();
		void display();
      };
  void llist::creation()
     {
       int num,ch;
       head=prev=NULL;
       do{
       NODE *temp;
       temp=new NODE;
       cout<<"Enter node information"<<endl;
       cin>>num;
       temp->info=num;
       temp->next=NULL;
       if (head==NULL)
	 head=prev=temp;
       else{
	 prev->next=temp;
	 prev=temp;
	}
       cout<<"Do you wanted to add more nodes(1-Yes or 2-No"<<endl;
       cin>>ch;
       }
       while(ch!=2);
     }
 void llist::display()
     {
      NODE *t;
      t=head;
      cout<<"The linked list contents are"<<endl;
      while(t!=NULL)
	{
	  cout<<t->info<<endl;
	  t=t->next;
	}
}
     
  int main()
    { 
      system("cls");
      llist l1;
      l1.creation();
      l1.display();
      getch();
    }
