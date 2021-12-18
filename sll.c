#include <stdio.h>
#include <stdlib.h>

void display();
void insert();
void delete();

struct node
{
    int data;
    struct node *next;
};

struct node* head = NULL;

void main()
{
    int c = 0;

    do
    {
        printf("1. Add \n2. Print \n3. Delete \n4. Exit \nEnter your choice: ");
        scanf("%d",&c);

        switch(c)
        {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: delete(); break;

        }

    }
    while(c != 4);

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

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");

    }
    else
    {
        printf("\n\n");
        struct node* temp = head;

        while(temp != NULL)
        {
            printf("%d ",temp->data);

            temp = temp->next;
        }
        printf("\n\n");
    }
}

void delete()
{
    if(head == NULL)
    {
        printf("The List is empty\n");

    }
    else
    {
        printf("\nEnter the element to delete: ");
        int element;
        scanf("%d",&element);



        struct node* prev = NULL;
        struct node* cur = head;

        while(cur->data != element)
        {
            if(cur->next == NULL)
            {
                printf("\nElement not found");
                break;
            }

            prev = cur;
            cur = cur->next;

        }

        if(head->data == element &&  head->next == NULL)
        {
            head = NULL;
            free(head);
            return;
        }

        if(cur == head && cur->data == element)
        {
             head = head->next;
        }

        else if(cur->next == NULL && cur->data != element)
        {
            printf("1\n");
            return;
        }
        else
        {
            prev->next = cur->next;
        }

    }
}
