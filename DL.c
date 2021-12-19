#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* head;
int len;

void insertatend();
void insertathead();
void insertatpos();
void display();
void back();
void delete();
struct node* getnewnode(int);
void main()
{
    int c;

    do
    {
        printf("1. Insert at head\n2. Insert at End\n3.Insert at a given position\n4. Delete given element\n5. Print (forward)\n6. Print (backwards)\n7. Exit\nEnter your choice: ");
        scanf("%d",&c);

        switch(c)
        {
            case 1: insertathead(); break;
            case 2: insertatend(); break;
            case 3: insertatpos(); break;
            case 4: delete(); break;
            case 5: display(); break;
            case 6: back(); break;
        }
    }
    while(c!=7);
}

struct node* getnewnode(int element)
{
    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->data = element;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void insertatend()
{
    printf("\nEnter the element to be inserted at the end: ");
    int element;
    scanf("%d",&element);

    struct node *newnode = getnewnode(element);
    ++len;

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    struct node* temp = head;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

}

void insertathead()
{
    printf("\nEnter the element to be inserted at the head: ");
    int element;
    scanf("%d",&element);

    struct node *newnode = getnewnode(element);
    ++len;

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;

}

void insertatpos()
{
    printf("\nEnter the position of the element: ");
    int pos;
    scanf("%d",&pos);

    if(pos<0 || pos>len)
    {
        printf("\nUnreachable location\n");
        return;
    }

    printf("\nEnter the element to be inserted at the %d position: ",pos);
    int element;
    scanf("%d",&element);
    ++len;

    int c = 0;
    struct node *prev = NULL;
    struct node *cur = head;

    while(c != pos)
    {
        prev = cur;
        cur = cur->next;
        ++c;
    }

    if(pos == 0)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }

    if(pos == len)
    {
        cur->next = newnode;
        newnode->prev = cur;
        return;
    }

    prev->next = newnode;
    newnode->next = cur;
    cur->prev = newnode;
    newnode->prev = prev;
}

void delete()
{
    printf("\nEnter the element to be deleted: ");
    int element;
    scanf("%d",&element);

    struct node *prev = NULL;
    struct node *cur = head;

    while(cur->data != element)
    {
        if(cur->next == NULL)
        {
            printf("\nElement not found\n");
            return;
        }
    }
}
