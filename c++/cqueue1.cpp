#include<iostream>
#define Max 5;
using namespace std;
int main(){
	int a[Max],front,rear,n,x,i;
	cqueue(){
			front=rear=-1;
            }
bool isEmpty(){
		if(front==-1){
			return 1;}
			else{return 0;
				}
		}
bool isFull(){
		if(((front==0&&rear=Max-1)||(front==rear+1)){
		return 1;
		}else {return 0;}
		}
 void enqueue(int x){
	if(isFull()){
		cout<<"\n queue is full\n";
		return;
	}else if(front==-1){
		front=0;
    }else if(rear==Max-1){
     rear=0;
	}else{
		rear=(rear+1)%n;
		a[rear]=x;
	}
}
int dequeue(){
	int x;
	if(isEmpty()){
		cout<<"\nQueue is empty";
	
	}x=a[front];
	
	 if(rear==front){
	 front=rear=-1
	 }
	else if(front==Max-1){
front=0;
}else{
	front=front+1;
	return x;
}

}

void put(){
		cout<<"\nElements of queue: ";
		for(i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<"\n";
	}







}


		
	



