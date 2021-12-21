# include <stdio.h>
#include <stdlib.h>

void insert();
void delete();
void display();

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void main()
{
    int ch;

    do
    {
        printf("1. Insert Element into List\n2. Delete Element from List\n3. Display the List\n4. Exit\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;

        }

    }
    while(ch != 4);
}

void insert()
{
    printf("\nEnter the element to be inserted: ");
    int element;
    scanf("%d",&element);

    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->data = element;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void delete()
{
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\nEnter the element to be deleted: ");
        int element;
        scanf("%d",&element);

        struct node* prev = head;
        struct node* cur = head;

        while(cur!=NULL && cur->data!=element)
        {
            prev = cur;
            cur = cur->next;
        }

        if(cur == NULL)
        {
            printf("\nElement not found\n");
            return;
        }
        else
        {
            if(prev == cur)
            {
                head = prev->next;
            }
            else
            {
                prev->next = cur->next;
            }
        }
    }
}

void display()
{
    if(head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    printf("\n");

    struct node* temp = head;

    while(temp != NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
