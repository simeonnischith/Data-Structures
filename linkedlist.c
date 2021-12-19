// CIRCULAR LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node* head = NULL;

void insertatend()
{
  //accept element from user
  int element;
  printf("\nEnter a number: ");
  scanf("%d",&element);

  //initialise newnode - connect to head
  struct node *newnode = (struct node*)(malloc(sizeof(struct node)));
  newnode->data = element;
  newnode->next = head;

  if(head != NULL)
  {
    struct node *temp = head;

    while(temp->next != head)
    {
      temp = temp->next;
    }

    temp->next = newnode;

  }
  else
  {
    newnode->next = newnode;
  }

  head = newnode;
}

void delete()
{

  struct node* prev = (struct node*)(malloc(sizeof(struct node)));
  struct node* cur = head;

  printf("\nEnter the element to be deleted: ");
  int key;
  scanf("%d",&key );


  while(cur->data != key)
  {
    if(cur->next == head)
    {
      printf("Element not found\n");
      break;
    }

    prev = cur;
    cur = cur->next;
  }

  //single node
  if(cur == head && cur->next == head)
  {

    head = NULL;
    free(head);
    return;
  }

  //more than one node - but element to be deleted is in first node
  if(cur == head)
  {
    prev = head;

    while(prev->next != head)
      prev = prev->next;

    head = cur->next;
    prev->next = head;

    free(cur);
    return;
  }

  //last node
  else if(cur->next == head)
  {
    if(cur->data == key)
      prev->next = head;


    return;
  }
  //every other node
  else
  {
    prev->next = cur->next;
    free(cur);
    return;
  }

}

void printlist()
{
  struct node *temp = head;
  printf("\n\n");

  if(head == NULL)
  {
    printf("\nList is empty\n");
    return;
  }

  do
  {

    printf("%d ",temp->data);

    temp = temp->next;

  }
  while(temp != head);

  printf("\n\n");
}

void main()
{
int ch;

do
{
  printf("1. Add\n2. Print List\n3. Delete\n4. Exit\nChoice: ");

  scanf("%d",&ch);

  if(ch==1) insertatend();
  else if(ch==2) printlist();
  else if(ch==3) delete();
  else if(ch != 4) printf("Invalid Choice, try again.\n\n");

}
while(ch != 4);

}
