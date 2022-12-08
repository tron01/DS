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
			case 7: display();
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
		front = new;
		rear = new;
		front->next = NULL:
		rear->next = NULL;
	}
	else {
		new->prev = rear;
		rear->next = new;
		rear=new;
		new->next = front;
	}
}

void deletion() {
	if(front == NULL){
		printf("Empty Queue \n");
	}
	else if(front->next == NULL) {
		front = NULL;
		rear = NULL;
		free(front);
		free(rear);
		printf("NODE DELETED");
	}
	else {
		ptr=head;
		head->next->prev = head->prev;
		head = head->next;
		free(ptr);
		printf("NODE DELETED");
	}
}

void display() {
	if(head == NULL) {
		printf("Empty Queue \n");
	} else {
		ptr = head;
		while(ptr->next != head){
			printf("<-|%p|%d|%p|->",ptr->prev,ptr->data,ptr->next);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
