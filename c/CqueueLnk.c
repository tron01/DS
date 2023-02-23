#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next, *prev;
	int data;
};

struct node *front=NULL, *rear=NULL,*ptr=NULL,*new=NULL;

void insertion();
void deletion();
void display();

void main() {
	int opt;
	do {
		printf("\nChoose the operation number : \n");
		printf("1.Insertion \n2.Deletion \n3.Display \n0.Exit : ");
		scanf("%d",&opt);
		switch(opt) {
			case 1: insertion();
							break;
			case 2: deletion();
							break;
			case 3: display();
							break;
			case 0:
			default:break;
		}
	} while(opt!=0);
}

void insertion() {
	new = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted : ");
	scanf("%d",&new->data);
	new->next = NULL;
	new->prev = NULL;
	if(front == NULL) {
	  new->next = new;
	  new->prev = new;
	  front = new;
		rear = new;
	}
	else {
		new->prev = rear;
		new->next = front;
		rear->next = new;
		rear=new;
		front->prev = new;
	}
}

void deletion() {
	if(front == NULL){
		printf("Empty Queue \n");
	}
	else if(front == rear) {
		front = NULL;
		rear = NULL;
		free(front);
		free(rear);
		printf("NODE DELETED");
	}
	else {
		ptr=front;
		front->next->prev = front->prev;
		front = front->next;
		rear->next = front;
		free(ptr);
		printf("NODE DELETED");
	}
}

void display() {
	if(front == NULL) {
		printf("Empty Queue \n");
	} else {
		ptr = front;
		do {
		  printf("%d ",ptr->data);
			ptr = ptr->next;
		} while( ptr != front);
		printf("\n");
	}
}
	
	
		
	
