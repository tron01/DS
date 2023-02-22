#include<stdio.h>
#include<stdlib.h>


#define N 5
int stack[N];
int top=-1;


void push();
void pop();
void display();

void main(){
	
	int opt;
	printf("1.Push\n2.POP\n3.Display\n4.Exit\n");
	do{
		printf("Enter the choice:");
		scanf("%d",&opt);
		switch(opt){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			break;
		}
	}while(opt!=5);
}
void push(){
int x;
printf("Enter the data:");
scanf("%d",&x);
if(top==N-1){
	printf("\n Overflow \n");

}else{
    top++;
    stack[top]=x;
}

}
void pop(){
int item;
if (top==-1){
printf("\nUnderFlow\n");
}else{
    item=stack[top];
    top--;
    printf("\n %d is Deleted \n",item);
}

}
void display(){
    int i;
	for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
	
}
