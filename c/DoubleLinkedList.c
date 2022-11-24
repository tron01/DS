#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head =NULL;
struct node *ptr =NULL;

int main(){
	
	int n ,i,em;
	struct node *newnode;
	printf("Enter the no of node:");
	scanf("%d",&n);
	for( i=1;i<=n;i++){
		newnode=(struct node *)malloc(sizeof(struct node *));
		printf("Enter the data :");
		scanf("%d",&em);
		newnode->data=em;
		newnode->prev=NULL;
		newnode->next=NULL;
		if(head==NULL){
			head=newnode;
		}else{
			ptr=head;
			while(ptr->next!=NULL){
				ptr= ptr->next;
				
			}
			ptr->next=newnode;
			newnode->prev=ptr;
		}
	}
	
	printf("Double Linked list:\n");
	ptr=head;
	while(ptr!=NULL){
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
	
	return 0;
	
}
