#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *prev;
  struct node *next;
  int data;
};

struct node *new = NULL, *ptr = NULL, *head = NULL;

void insert_last ();
void delete_last ();
void insert_beginning ();
void delete_beginning ();
void display ();
void insert_after_key ();
void delete_between ();
void create_node ();

int main ()
{
  int opt;
  do
    {
      printf ("\nEnter the choice: \n");
      printf("1.Insertion Beginning \n2.Inserting after key \n3.Insertion last \n4.Delete beginning \n5.Delete In between \n6.Delete last \n7.Display \n0.Exit : ");
      scanf ("%d", &opt);
      switch (opt)
	{
	case 1:
	    insert_beginning ();
	  break;
	case 2:
	  insert_after_key();
	  break;
	case 3:
	   insert_last ();
	  break;
	case 4:
	  delete_beginning ();
	  break;
	case 5:
	   delete_between ();
	  break;
	case 6:
	   delete_last ();
	  break;
	case 7:
	  display ();
	  break;
	case 0:
	default:
	  break;
	}
    }
  while (opt != 0);
  return 0;
}

void
create_node ()
{
  new = (struct node *) malloc (sizeof (struct node));
  printf ("Enter the data to be inserted : ");
  scanf ("%d", &new->data);
  new->next = NULL;
  new->prev = NULL;
}

void
insert_last ()
{
  create_node ();
  if (head == NULL)
    {
      head = new;
    }
  else
    {
      ptr = head;
      while (ptr->next != NULL)
	{
	  ptr = ptr->next;
	}
      ptr->next = new;
      new->prev = ptr;
    }
}

void
insert_beginning ()
{
  create_node ();
  if (head == NULL)
    {
      head = new;
    }
  else
    {
      head->prev = new;
      new->next = head;
      head = new;
    }
}

void
insert_after_key ()
{
  int key;
  create_node ();
  printf ("Enter the key where the node to be inserted : ");
  scanf ("%d", &key);
  ptr = head;
 while(ptr->next!=NULL && ptr->data!=key)
		{
		ptr=ptr->next;
		}
	if(ptr->next==NULL)
		{
		ptr->next=new;
		ptr->prev=ptr;
		}
	else
	{
	new->next = ptr->next;
      new->prev = ptr;
      ptr->next = new;
      ptr->next->prev = new;
	}
}
void
delete_beginning ()
{
  if (head == NULL)
    {
      printf ("Empty List");
    }
  else if (head->next == NULL)
    {
      head = NULL;
      free (head);
      printf ("NODE DELETED");
    }
  else
    {
      ptr = head;
      head = head->next;
      head->prev = NULL;
      free (ptr);
      printf ("NODE DELETED");
    }
}

void
delete_last ()
{
  if (head == NULL)
    {
      printf ("Empty List \n");
    }
  else if (head->next == NULL)
    {
      head = NULL;
      free (head);
      printf ("\nnode deleted\n");
    }
  else
    {
      ptr = head;
      while (ptr->next != NULL)
	{
	  ptr = ptr->next;
	}
      ptr->prev->next = NULL;
      free (ptr);
      printf ("\nnode deleted\n");
    }
}

void
delete_between ()
{
  int key;
  printf ("Enter the key where the node to be deleted : ");
  scanf ("%d", &key);
  if (head->data == key)
    {
      delete_beginning ();
    }
 else if (head == NULL)
    {
      printf ("\nlist is empty\n");
    }
  else
    {
      ptr = head;
      while (ptr->next != NULL && ptr->data != key)
	{
	  ptr = ptr->next;
	}
	
	  
	
	
      if (ptr == NULL)
	printf ("\nelement not found\n");
      else
	 if(ptr->next ==NULL) {
	 	delete_last ();
	 }else {
	    ptr->prev->next = ptr->next;
	    if (ptr->next != NULL)
	    ptr->next->prev = ptr->prev;
	    else
	    ptr->next = NULL;
	    free(ptr);
	printf("node deleted");
    }}
}

void display ()
{
  if (head == NULL)
    {
      printf ("Empty List \n");
    }
  else
    {
      ptr = head;
      while (ptr != NULL)
	{
	  printf ("%d ", ptr->data);
	  ptr = ptr->next;
	}
      printf ("\n");
    }
}
