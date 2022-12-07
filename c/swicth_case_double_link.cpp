#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertion_beginning();  
void insertion_last();  
void insertion_specified();  
void deletion_beginning();  
void deletion_last();  
void deletion_specified();  
void display();  
void search();  
int main ()  
{  
int choice =0;  
    while(choice != 9)  
    {    
         
printf("\n1.InsertFirst\n2.Insert last\n3.InsertiBtew\n4.DeleteFirst\n5.Deletelast\n6.DeleteInBte");     printf("\n7.search\n8.display\n9.exit");
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:insertion_beginning();  
            break;  
            case 2:insertion_last();  
            break;  
            case 3:insertion_specified();  
            break;  
            case 4:deletion_beginning();  
            break;  
            case 5:deletion_last();  
            break;  
            case 6:deletion_specified();  
            break;  
            case 7:search();  
            break;  
            case 8:display();  
            break;  
            case 9:exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
    return 0;
}  
void insertion_beginning()  
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value:");  
    scanf("%d",&item);  

   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  

}  
void insertion_last()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value:");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  

       }  
     printf("\nnode inserted\n");  
    }  
void insertion_specified()  
{  
 struct node *ptr,*temp;  
   int item,loc,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n OVERFLOW");  
   }  
   else  
   {  
       temp=head;  
       printf("Enter the location:");  
       scanf("%d",&loc);  
       for(i=0;i<loc;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\n There are less than %d elements", loc);  
               return;  
           }  
       }  
       printf("Enter value:");  
       scanf("%d",&item);  
       ptr->data = item;  
       ptr->next=temp;
       ptr->prev=temp->prev;
       temp->prev->next=ptr;
       temp->prev=ptr;  
       printf("\nnode inserted\n");  
   }    
}  
void deletion_beginning()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  

}  
void deletion_last()  
{  
    struct node *ptr;  
     ptr = head; 
    if(ptr == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(ptr->next == NULL)  
    {  
        head = NULL;   
        free(ptr);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
     
      while(ptr->next !=NULL){
      	ptr=ptr->next;
	  }
	  
         
              
      
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}  
void deletion_specified()  
{  
     struct node *ptr, *temp,*ptr2;  
    int key,i;  
   if(head==NULL){
     printf("\n UNDERFLOW");   
  }else{
    
       temp = head;
       printf("Enter the key node");
       scanf("%d",&key);
       
       while(temp->next!=NULL){
       	 if(temp->data==key){
       	    break;
	     }else{
	   	 temp=temp->next;
	      }
	          
	   }
	        if(temp->next!=NULL){
	           
	           	temp->prev->next =temp->next->prev;
	            temp->next->prev =temp->prev->next;
	           	
	           	free(temp);
			   }
	        
			   ptr=temp->prev;
			   ptr->next=NULL;
			   free(temp);
  } 
}  
void display()  
{  
    if(head==NULL){
    	printf("\n  Empty  \n"); 
	} else{
	struct node *ptr;  
    printf("\n printing values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    } 
	}
}   
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     

}
