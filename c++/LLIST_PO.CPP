
/*linked poly adiition*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
   {
    int coe,exp;
    struct node *next;
    };
 typedef struct node PNODE;
 class lpoly
     {
	public:
	    PNODE *p1,*p2,*p3;
	    PNODE * creation();
	    PNODE * polyadd(PNODE *p1, PNODE *p2);
	    void poly_disp(PNODE *p);
      lpoly()
       {
	p1=p2=p3=NULL;
       }
      };
 int main()
    { 
        	system("cls");

      lpoly lp;
      cout<<"Enter First Polynomial terms "<<endl;
      lp.p1=lp.creation();
      cout<<"Enter Second Polynomial terms "<<endl;
      lp.p2=lp.creation();
      lp.p3=lp.polyadd(lp.p1,lp.p2);
      cout<<"The first polynomial is "<<endl;
      lp.poly_disp(lp.p1);
      cout<<endl<<"The second polynomial is "<<endl;
      lp.poly_disp(lp.p2);
      cout<<endl<<"The third polynomial is "<<endl;
      lp.poly_disp(lp.p3);
      getch();
    }
 PNODE * lpoly::creation()
     {
       int c,e,ch;
       PNODE *prev,*temp,*phead;
       phead=prev=NULL;
       do
       {
       PNODE *temp;
       temp=new PNODE;
       cout<<"Enter coe & Exp "<<endl;
       cin>>c;
       cin>>e;
       temp->coe=c;
       temp->exp=e;
       temp->next=NULL;
       if (phead==NULL)
	 phead=prev=temp;
       else
	{
	 prev->next=temp;
	 prev=temp;
	}
       cout<<"Do you wanted to add more terms(1-Yes or 2-No"<<endl;
       cin>>ch;
       }
       while(ch!=2);
       return(phead);
     }

 void lpoly::poly_disp(PNODE *p)
     {
      PNODE *t;
      t=p;
      while(t!=NULL)
	{
	  cout<<t->coe<<"x"<<t->exp<<"  ";
	  t=t->next;
	}
     }
 PNODE * lpoly::polyadd(PNODE *p1,PNODE *p2)
     {
       PNODE *t1,*t2,*nterm,*prev,*p3=NULL;
       t1=p1;t2=p2;
       while(t1!=NULL && t2!=NULL)
	 {
	   nterm=new PNODE;
	   if(t1->exp>t2->exp)
	     {
	      nterm->coe=t1->coe;
	      nterm->exp=t1->exp;
	      t1=t1->next;
	     }
	   else if(t1->exp<t2->exp)
	     {
	      nterm->coe=t2->coe;
	      nterm->exp=t2->exp;
	      t2=t2->next;
	     }
	   else
	      {
	       nterm->coe=t1->coe+t2->coe;
	       nterm->exp=t1->exp;
	       t1=t1->next;
	       t2=t2->next;
	      }
	   nterm->next=NULL;
	   if(p3==NULL)

	     p3=prev=nterm;

	   else
	     {
	      prev->next=nterm;
	      prev=nterm;
	     }
	  }
	  if(t1!=NULL)
	    while(t1!=NULL)
	       {
		nterm=new PNODE;
		nterm->coe=t1->coe;
		nterm->exp=t1->exp;
		nterm->next=NULL;
		prev->next=nterm;
		prev=nterm;
		t1=t1->next;
	       }
	  else
	      while(t2!=NULL)
	       {
		nterm=new PNODE;
		nterm->coe=t2->coe;
		nterm->exp=t2->exp;
		nterm->next=NULL;
		prev->next=nterm;
		prev=nterm;
		t2=t2->next;
	       }
	  return(p3);
	 }
