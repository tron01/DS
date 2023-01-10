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
struct node* deleteNode(struct node *node, int value);
struct node* minNode(struct node *root);



// To find the minimum value
struct node* minNode(struct node *root) {
    if (root->left != NULL)
        return minNode(root->left);
    else
        return root;
}

// Delete a node form tree
struct node* deleteNode(struct node *node, int value) {
    if(node == NULL) {
        return NULL;
    }
    else {

        if(value < node->data)
            node->left = deleteNode(node->left, value);

        else if(value > node->data)
            node->right = deleteNode(node->right, value);

        // If value is equal to node's data node to be deleted is found
        else {
            // Deletion node has no childern
            if(node->left == NULL && node->right == NULL)
                node = NULL;

            // Deletion node has on right child
            else if(node->left == NULL) {
                node = node->right;
            }

            // Deletion node has one right child
            else if(node->right == NULL) {
                node = node->left;
            }

            // Deletion node has two childern
            else {
                // Minmum value from right sub-tree
                struct node *temp = minNode(node->right);
                // Exchange the data between node and temp
                node->data = temp->data;
                // Delete the node duplicate node from right subtree
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
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
       deleteNode(root,key);
       break;
case 6:exit(0);
   break;
 }
  }

}

