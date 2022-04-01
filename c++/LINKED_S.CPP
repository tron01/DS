
/*linked stack*/


#include<iostream>

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node{
    int info;
    struct node *next;
    } NODE;

 
 class llist
     {
      NODE *top;
      public:
	    void push();
	    void pop();
	    void put();
      llist()
       {
	top=NULL;
       }
      };
 int main()
    { 
	    	system("cls");
	  llist l1;
      int ch;
      do
      {
      cout<<"\n------------------\n";
      cout<<"1. PUSH"<<endl;
      cout<<"2. POP "<<endl;
      cout<<"3. display"<<endl;
      cout<<"\n------------------";

      cout<<"\nEnter the choice : "<<endl;
      cin>>ch;
      switch(ch)
	{
	case 1:l1.push();
	       break;
	case 2:l1.pop();
	       break;
	case 3:l1.put();
	       break;
	       
	}

     }while(ch!=4);
    getch();
    }
    
 void llist::push()
     {
       int num,ch;
       NODE *temp;
       temp=new NODE;
       cout<<"\nEnter node information: "<<endl;
       cin>>num;
       temp->info=num;
       temp->next=NULL;
       if(top==NULL)
	 top=temp;
       else
	{
	 temp->next=top;
	 top=temp;
	}
      }

void llist::pop()
     {
      if(top==NULL)
       cout<<"\nThe stack is empty"<<endl;
      else
	  {
	cout<<"\nThe deleted element is : ";
	cout<<top->info<<endl;
	top=top->next;
       }
    }
void llist::put(){
     	
     NODE *t;
	 t=top;
	 cout<<"\n****************************\n";
	 while(t!=NULL){
	 	
	 	cout<<t->info<<" ";
	 	t=t->next;
	 	 }
		  cout<<"\n****************************\n";	
	 }
