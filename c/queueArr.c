#include<stdio.h>
#include<stdlib.h>


#define N 5
int q[N];
int front,rear=-1;


void enqueue(int);
void dequeue();
void display();

void main(){
	
	int opt,x;
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	do{
		printf("Enter the choice:");
		scanf("%d",&opt);
		switch(opt){
			
			case 1:printf("Enter the data:");
			       scanf("%d",&x);
				   enqueue(x);
				   break;
			case 2:dequeue();
			break;
			
			case 3:display();
			break;
			case 4:exit(0);
			break;
		}
	}while(opt!=5);
}
void enqueue(int item){

if(rear==N-1){
	printf("Queue is full");
}else if(front==-1 && rear==-1) {
	front,rear=0;
	q[rear]=item;
}else{
	rear=rear+1;
	q[rear]=item;
}


}
void dequeue(){
	int item;
	if(front==-1 && rear==-1){
		printf("Queue is empty");
	}else if(rear==front){
		item=q[front];
		front,rear=-1;	
	}else{
		item=q[front];
		front=(front+1);	
	}
	printf("%d is deleted\n",item);

}
void display(){
   
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        printf("\n Queue is empty\n");    
    }  
    else  
    {  
       for(i;i<rear+1;i++){
       	printf("%d\n",q[i]);
	   }
    }  
	
}
