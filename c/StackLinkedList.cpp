#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
void push();
void pop();
void display();

struct node *TOP=NULL;
int main(){
	
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
	
	return 0;
	
}
void push(){
struct node *newnode;
int em;
newnode=(struct node *)malloc(sizeof(struct node *));
if(newnode==NULL){
	printf("Overflow\n");
}else{
printf("Enter the Element:");
scanf("%d",&em);
newnode->data=em;
newnode->next=TOP;
TOP=newnode;
}

}
void pop(){
	struct node *temp;
	temp=TOP;
	if(TOP==NULL)
	{
		printf("UNDERFLOW\n");
	}else{
		printf("%d:is deleted\n",temp->data);
		TOP=temp->next;
		free(temp);
	}
}
void display(){
	struct node *temp;
	temp=TOP;
	
	if(TOP==NULL){
		printf("Empty\n");
	}else{
		while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	    }
	}
	
}
