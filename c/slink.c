#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

void beginsert()
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  printf("\n enter data:");
  scanf("%d", &newnode->data);
  newnode->next = head;
  head = newnode;
}

void lastinsert()
{
  struct node *newnode, *temp;
  int x;
  newnode = (struct node *)malloc(sizeof(struct node *));
  printf("\n enter data:");
  scanf("%d", &x);
  newnode->data = x;
  if (head == NULL)
  {
    newnode->next = NULL;
    head = newnode;
  }
  else
  {
    temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
  }
}

void delitem()
{
  struct node *ptr, *prev;
  int key;
  printf("Enter the key to delete : ");
  scanf("%d", &key);
  if (head == NULL)
    printf("Empty list");
  else if (head->data == key)
    head = head->next;
  else
  {
    ptr = head;
    while (ptr->data != key && ptr->next != NULL)
    {
      prev = ptr;
      ptr = ptr->next;
    }
    if (ptr->data != key)
    {
      printf("No data found");
    }
    else if (ptr->next == NULL)
    {
      prev->next = NULL;
      free(ptr);
      printf("NODE DELETED");
    }
    else
    {
      prev->next = ptr->next;
      free(ptr);
      printf("NODE DELETED");
    }
  }
}

void search()
{
  struct node *ptr;
  int val, flag = 0;
  printf("\n enter the value to be searched");
  scanf("%d", &val);
  if (head == NULL)
    printf("\nEmpty List\n");
  else
  {
    ptr = head;
    while (ptr != NULL)
    {
      if (ptr->data == val)
      {
        printf("Item Found in List");
        flag = 1;
        break;
      }
      else
        ptr = ptr->next;
    }
    if (flag == 0)
      printf("Item Not Found in List");
  }
}

void display()
{
  struct node *ptr;
  if (head == NULL)
    printf("list is Empty");
  else
  {

    printf("%d", head->data);
    ptr = head;
    while (ptr != NULL)
    {
      printf("%d->", ptr->data);
      ptr = ptr->next;
    }
    printf("null");
  }
}

void main()
{
  int opt;
  do
  {
    printf("\nEnter your choice:\n1. Insert at beginning\n2.Insert at end \n3.delete at position \n4.search \n5.display");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
      beginsert();
      break;
    case 2:
      lastinsert();
      break;
    case 3:
      delitem();
      break;
    case 4:
      search();
      break;
    case 5:
      display();
      break;
    default:
      printf("invalid choose");
    }
  } while (opt != 6);
}
