#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	
};
struct node *head=NULL;
int main(){
	int n,em,i;
	struct node *newnode,*temp;
	printf("Enter the size of node:");
	scanf("%d",&n);
	for( i=0;i<n;i++){
    newnode=(struct node *)malloc(sizeof(struct node *));
    printf("Enter the Elements:");
	scanf("%d",&em);
	newnode->data=em;
	newnode->next=NULL;
    if(head==NULL){
	 head=newnode;
         }else{
         	newnode->next=head;
         	head=newnode;
		 }
	}
	printf("---LinkedList---\n");
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}

	
	
	return 0;
}
