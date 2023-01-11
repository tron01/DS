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



/*
Algorithm search
ROOT is a pointer to the root node of the tree.
X is the element to be searched in the binary search tree.
1. ptr=ROOT
2. while(ptr!=NULL)
 if (ptr->data==x)
 print(“Data Present")
 goto step3
 end if
if (x>ptr->data)
 ptr=ptr->right
else
ptr=ptr->left
end if
end while
3. if (ptr==NULL)
print("data not present")
end if
4. stop
*/

/*
Algorithm insert
ROOT is a pointer to the root node of the tree.
X is the element to be inserted in to the tree.
1. ne=GetNode()
2. if (ne==NULL)
printf("\n insufficient Memory");
goto step8
endif
3. ne->right=ne->left=NULL;
 ne->data=x;
4. if (ROOT==NULL)
ROOT=ne;
Goto step8
End if
5. ptr=ROOT;
6. while(ptr!=NULL)
if (x==ptr->data)
print("Item present in the tree");
goto step7
end if
if (x>ptr->data)
ptr1=ptr;
ptr=ptr->right;
 else
ptr1=ptr;
 ptr=ptr->left;
End if
End while
7. if (ptr==NULL)
if (x>ptr1->data )
ptr1->right=ne;
else
ptr1->left=ne;
end if
end if
8. Stop
*/

/*
Algorithm delet(x)
ROOT is a pointer to the root node of the tree.
X is the element to deleted from the tree.
1. if (ROOT==NULL)
 printf("\nTree is empty");
return;
 end if
2. parent=NULL ;
 ptr=ROOT;
3. while(ptr!=NULL)
 if (ptr->data==x)
break;
end if
parent=ptr;
 if (x > ptr->data)
ptr=ptr->right;
else
ptr=ptr->left;
end if
end while
4. if (ptr==NULL)
 printf("Item Not Present");
goto step8
 end if
5. if (ptr->right==NULL && ptr->left==NULL) //case1 if (parent==NULL)
ROOT=NULL;
   else if (parent->right==ptr)
        parent->right=NULL;
        else
        parent->left=NULL;
   end if
print("Element deleted");
 free(ptr);
goto step8
 end if
6. if(ptr->right!=NULL && ptr->left!=NULL) //case 3 //find the inorder successor p
p=ptr->right;
while(p->left!=NULL)
p=p->left;
end while
dat=p->data;
delet(p->data); //recursive call
ptr->data=dat;
goto step8
 end if
7. //case2
 if (parent==NULL)
if (ptr->right==NULL)
 ROOT=ptr->left;
 else
ROOT=ptr->right;
End if
 else
if (parent->right==ptr)
if (ptr->right==NULL)
 parent->right=ptr->left;
else
 parent->right=ptr->right;
end if
 else
if (ptr->left==NULL)
parent->left= ptr->right;
else
parent->left=ptr->left;
end if

 print("Element deleted");
 free(ptr);
8.stop
*/

/*
Algorithm InOrder(ptr)
 ptr is the pointer to the root node of the binary tree1. If (ptr!=NULL)
InOrder(ptr->LC)
Visit(ptr->data)
InOrder(ptr->RC)
 Endif
2. Stop
Algorithm PreOrder(ptr)
ptr is the pointer to the root node of the binary tree1. If (ptr!=NULL)
Visit(ptr->data)
PreOrder(ptr->LC)
PreOrder(ptr->RC)
 endif
2. stop
Algorithm PostOrder(ptr)
ptr is the pointer to the root node of the binary tree1. If (ptr!=NULL)
PostOrder(ptr->LC)
PostOrder(ptr->RC)
Visit(ptr->data)
 endif
2. Stop
*/