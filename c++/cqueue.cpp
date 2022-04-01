#include<iostream>
using namespace std;
class cqueue{
	int a[10],front,rear,x,n,i,c;

	public:
		void insert();
		void dele();
        void put();
        void menu();
		cqueue(){
          front=rear=0;
	   }
};

void cqueue::insert(){
if((rear+1)%n==front){
	cout<<"\nThe queue is full";
}else{
	if(front==-1)
	front=0;
	}
	cout<<"\nEnter the elemnts: ";
	cin>>x;
    rear=(rear+1)%n;
	a[rear]=x;	
   }


void cqueue::dele(){
 if(front==-1){
 	cout<<"\nqueue is empty: ";
 	}else{
 		x=a[front];
		 }
 		if(front==rear){
	front=-1;
	rear=-1;
	}else
	front=(front+1)%n;
 		cout<<"\nThe element deleted: "<<x;
 			
	 }

void cqueue::put(){
	  	for(i=0;i<n;i++){
	  		cout<<a[i]<<" ";
		  }
}




void cqueue::menu(){
	cout<<"\nEnter the limit: ";
	cin>>n;
    
	
while(1){
	
	cout<<"\n______________________";
		cout<<"\n1.insert\n2.delete\n3.display\n4.Exit";
			cout<<"\n______________________\n";
			cout<<"Enter the choice: ";
		cin>>c;
		switch(c){
			case 1:insert();
			break;
			case 2:dele();
			break;
			case 3:put();
			break;
		}
    }
		
}

int main(){
	cqueue c;
	c.menu(); 


}
