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
struct node * deleteT(struct node *root,int key);
void insert();

struct node * deleteT(struct node *root,int k){
struct node *temp,*succ,*succParent;
if(root == NULL){



}else{
 if(root->data > k ){
  
  root->left = deleteT(root->left, k);
   return root;
 }else  if (root->data < k) {   
       root->right = deleteT(root->right, k);
       return root;
  }
    // If one of the children is empty
    if (root->left == NULL) {
         temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
         temp = root->left;
        free(root);
        return temp;
    }
 
    // If both children exist
    else {

   succParent = root;
 
        // Find successor
         succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->data = succ->data;
 
        // Delete Successor and return root
        free(succ);
       return root;
  }
 

}

}
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
int c=0,key;

while(c!=6){
printf("\n1.insert\n2.InOrder\n3.PreOrder \n4.PostOrder\n5.Delete \n6.exit \n/Enter your choice:");
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
case 5:printf("Enter the key to delete:");
       scanf("%d",&key);
       deleteT(root,key);
       break;
case 6:exit(0);
   break;
 }
  }

}


