
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

void insert(int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void search(int);
void delete(int);
//struct node* min_val_node(struct node*);

void main(){
	int ch=0,key;
	do{
		printf("\n1.Insertion\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal");
		printf("\n5.Search\n6.Delete an element\n7.Exit");
		printf("\n Enter your choice=");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\n Enter the data to be inserted =");
				scanf("%d",&key);
				insert(key);
				break;
			case 2:printf("\n------------\n"); 
                               inorder(root);
                               printf("\n------------"); 
				break;
			case 3:printf("\n------------\n"); 
                               preorder(root);
			       printf("\n------------");
                               break;
			case 4:printf("\n------------\n"); 
                               postorder(root);
                               printf("\n------------");
			       break;
			case 5: printf("\n Enter the key to be searched=");
				scanf("%d",&key);
                                printf("\n-----------------------"); 
				search(key);
                                printf("\n-----------------------"); 
				break;
			case 6: printf("\n Enter the key to be deleted=");
				scanf("%d",&key);
                                printf("\n------------------------"); 
				delete(key);
                                printf("\n------------------------"); 
				break;
			case 7: exit;
				printf("\n \n");
				break;
			default:printf("\n Invalid Choice ");				
		}		
	}while(ch!=7);
}

void insert(int key){
	struct node *new=NULL,*parent=NULL,*ptr=NULL;
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL){
		printf("\n Insufficient Memory");
		return;	
	}
	else{
		new->data=key;
		new->left=NULL;
		new->right=NULL;
		if(root==NULL)
			root=new;
		else{
			
			ptr=root;
			while(ptr!=NULL){
				if(key==ptr->data){
					printf("\n Duplicate elements not allowed");
					break;				
				}
				else if(key>ptr->data){
					parent=ptr;
					ptr=ptr->right;
				}
				else{
					parent=ptr;
					ptr=ptr->left;				
				}
			}
			
			if(ptr==NULL){
				if(key>parent->data)
					parent->right=new;
				else
					parent->left=new;
			}	
		}	
	}	
}

void inorder(struct node *ptr){
	if(root==NULL)
		printf("\n Tree is empty");	
	else{
		if(ptr!=NULL){	
			inorder(ptr->left);
			printf("%d ",ptr->data);
			inorder(ptr->right);			
		}
	}
}

void preorder(struct node *ptr){
	if(root==NULL)
		printf("\n Tree is empty");	
	else{
		if(ptr!=NULL){	
			printf("%d ",ptr->data);
			preorder(ptr->left);
			preorder(ptr->right);	
		}		
	}
}

void postorder(struct node *ptr){
		if(root==NULL)
		printf("\n Tree is empty");	
	else{
		if(ptr!=NULL){	
			postorder(ptr->left);
			postorder(ptr->right);
			printf("%d ",ptr->data);	
		}		
	}
}

void search(int key){
	struct node *ptr=NULL,*parent=NULL;
	if(root==NULL)
		printf("\n Tree is empty");
	else{
		ptr=root;
		while(ptr!=NULL){
			if(key==ptr->data){
				printf("\n %d present  tree.",ptr->data);
				break;				
			}
			else if(key>ptr->data){
				parent=ptr;
				ptr=ptr->right;
			}
			else{
				parent=ptr;
				ptr=ptr->left;				
			}
		}
		if(ptr==NULL)
			printf("\n %d not  tree.",key);
	}
}

void delete(int key){
	struct node *ptr=NULL;
	if(root==NULL)
		printf("\n Tree is empty");
	else{
		struct node *parent=NULL;
		ptr=root;
		while(ptr!=NULL){
			
			if(ptr->data==key){
				break;
			}
			else{
				parent=ptr;
				if(key > ptr->data)
					ptr=ptr->right;
				else
					ptr=ptr->left;
			}
		}
		if(ptr==NULL){
			printf(" \n %d is not  in the tree",key);

		}
		else
		{
			
				if(ptr->right==NULL && ptr->left==NULL){
					if(parent==NULL)
						root=NULL;
					else if(parent->right==ptr)
						parent->right=NULL;
					else 
						parent->left=NULL;
					free(ptr);
				}
				
				else if(ptr->right!=NULL && ptr->left!=NULL){
					struct node *p=NULL;
					p=ptr->right; 
					while(p->left!=NULL)
						p=p->left;
					int dat=p->data;
					delete(dat); 
					ptr->data=dat;	
				}else{
					if(parent==NULL)
					{
						if(ptr->right==NULL)
							root=ptr->left;
						else
							root=ptr->right;					
					}else{
						if(parent->right==ptr){
							if(ptr->right==NULL)
								parent->right=ptr->left;
							else
								parent->right=ptr->right;			
						}	
						else{
							if(ptr->left==NULL)
								parent->left=ptr->right;
							else
								parent->left=ptr->left;				
						}
						free(ptr);
					}
				}
                     printf("\n element deleted");
		}
		
	}

}
