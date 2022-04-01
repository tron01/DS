#include<iostream>
using namespace std;
struct node{
	int info;
	struct node *next;
};
typedef struct node NODE;

class list{
NODE *head,*prev;
public:
	void get();
	void put();
  };
 
void list::get(){
	int num,c;
	head=prev=NULL;
	do{ 
	  NODE *temp;
	  temp=new NODE;
	  cout<<"\nEnter the node info: ";
	  cin>>num;
	  temp->info=num;
	  temp->next=NULL;
      if(head==NULL){
      	head=prev=temp;
	  }else{
	  	prev->next=temp;
	  	prev=temp;
	  }
	  cout<<"\nDo you want one more node(1.yes 2.No)";
	  cin>>c;
	  
	}while(c!=2);
} 
void list::put(){
	NODE *t;
	t=head;
	cout<<"\nThe linked list contents are: ";
	while(t!=NULL){
		cout<<t->info<<" ";
		t=t->next;
	}
}
 int main(){
  	list s;
  	s.get();
  	s.put();
  }
