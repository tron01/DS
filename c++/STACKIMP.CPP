#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>

using namespace std;
class stack
{
int st[100];
int top,n;
public:
  
  void stacksize();
  
  
  void push();
  
  pop();
  
  void display();
  
  stack()
  { top=-1;
  }
  
  
};


void stack::stacksize()
  {
   
   cout<<"Enter the size of the stack"<<endl;
   cin>>n;
  }
  
void stack::push()
  {
  int value;
  if(top==n-1)
   {
    cout<<"The stack is full"<<endl;
    getch();
   }
  else
   {
    cout<<" Enter the new element"<<endl;
    cin>>value;
    top=top+1;
    st[top]=value;
    }
  }
  
stack::pop()
    {
     int temp;
     if(top==-1)
      {
       cout<<" The stack is empty"<<endl;
       getch();
       return(-1);
      }
     else
      {
       temp=st[top];
       top=top-1;
       return(temp);
     }
   }
   
   
void stack::display()
  {
   cout<<"The stack contents are"<<endl;
   int t=top;
   while(t>=0)
     {
      cout<<st[t]<<endl;
      t=t-1;
     }
   getch();
  }
 int main()
 {
  stack s;
  int ch,t;
  s.stacksize();
  do
   {
   
    cout<<"1-PUSH"<<endl;
    cout<<"2-POP"<<endl;
    cout<<"3-DISPLAY"<<endl;
    cout<<"4-EXIT"<<endl;
    cout<<" Enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1: s.push();
	    break;
    case 2: t=s.pop();
	    if(t!=-1)
	    cout<<"The deleted element is :"<<t;
	    break;
    case 3: s.display();
	    break;
    case 4: exit(0);

    default: cout<<" Wrong choice"<<endl;
    }
    getch();
    
   }while(ch!=4);
   return 0;
 }
