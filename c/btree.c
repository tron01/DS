#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *left;
  struct node *right;
  int data;
};

  struct node *root =NULL;
  
void InOrder( struct node *r);
void PostOrder( struct node *r);
void PreOrder( struct node *r);


void insert(){
int x;
struct node *newnode,*ptr,*ptr1;
newnode = (struct node *) malloc (sizeof (struct node));
if(newnode==NULL){
 printf("!No Space");

 }else{
 printf ("Enter the data to be inserted : ");
 scanf ("%d",&x);
 newnode->right = newnode->left =NULL;
 newnode->data=x;  

 
if(root==NULL){
  root = newnode;
  
  }else{

  ptr=root;
  while(ptr!=NULL){
     if(x==ptr->data){
         printf("\nitem in the tree!!");
         break;
        }else if(x>ptr->data){
         ptr1=ptr;
         ptr=ptr->right;
        
       }else{
           ptr1=ptr;
         ptr=ptr->left;
          }
   }
if(ptr==NULL){
    if(x>ptr1->data){
      ptr1->right=newnode;
    }else{
    ptr1->left=newnode;
    }
 }
 
 } 
}

}
void InOrder(struct node *ptr)
{
if(ptr!=NULL){

InOrder(ptr->left);
printf("%d ",ptr->data);
InOrder(ptr->right);
}
}
void PreOrder(struct node *ptr)
{
if(ptr!=NULL){

printf("%d ",ptr->data);
PreOrder(ptr->left);
PreOrder(ptr->right);
}
}
void PostOrder(struct node *ptr)
{
if(ptr!=NULL){

PostOrder(ptr->left);
PostOrder(ptr->right);
printf("%d ",ptr->data);
}
}

void main(){
int c=0;

while(c!=5){
printf("\n1.insert\n2.InOrder\n3.PreOrder \n4.PostOrder\n5.exit \n/Enter your choice:");
scanf("%d",&c);
switch(c){
case 1:insert();
  break;
case 2:InOrder(root);
   break;
case 3:PreOrder(root);
   break;
case 4:PostOrder(root);
   break;
case 5:exit(0);
   break;
 }
  }

}


