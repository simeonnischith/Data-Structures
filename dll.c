#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

struct node* getnewnode(int);
void insert();
void delete();
void display();
void back();
void insertatpos();

void main()
{
    int c;

    do
    {
        printf("\n\n");

        printf("1. Insert\n2. Print\n3. Delete\n4. Exit\n5. Print in Reverse\n6. Insert at given postition \nEnter your choice: ");
        scanf("%d",&c);

        switch(c)
        {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: delete(); break;
            case 5: back(); break;
            case 6: insertatpos(); break;
        }

        printf("\nlength= %d \n",count);

    }
    while(c!=4);

}

void insert()
{
     count = count + 1;

    printf("Enter the element to insert: ");
    int element;
    scanf("%d",&element);

    struct node* newnode = getnewnode(element);

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
        newnode->prev = temp;
    }
}

void delete()
{

    if(head == NULL)
    {
        printf("List is empty");
        return;
    }

    int element;
    printf("\nEnter the element to be deleted: ");
    scanf("%d",&element);

    struct node* prev = NULL;
    struct node* cur = head;

    while(cur->data != element)
    {
        if(cur->next == NULL)
        {
            printf("\nElement not found\n");
            break;
        }

        prev = cur;
        cur = cur->next;
    }

    if(cur == head && cur->next == NULL)
    {

        head = NULL;
        free(head);
        count = count - 1;
        return;

    }

    if(cur == head)
    {
        head = head->next;
        head->prev = NULL;
        count = count - 1;
        return;
    }
    if(cur->next == NULL && cur->data != element)
    {
        return;
    }

    if(cur->next == NULL)
    {
        prev->next = NULL;
        cur = NULL;
        count = count - 1;
        free(cur);
    }
    else
    {

        prev->next = cur->next;
        cur->next->prev = prev;
        count = count - 1;
        free(cur);
    }

}

void display()
{
    printf("\n\n");
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("\n\n");
}

void back()
{
    printf("\n\n");

    if(head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    struct node *last = head;

    while(last->next!= NULL)
    {
        last = last->next;
    }

    while(last != NULL)
    {
        printf("%d ",last->data);

        last = last->prev;
    }

}

void insertatpos()
{
    int pos;
    printf("Enter the position to add element: ");
    scanf("%d",&pos);

    if(pos>count && pos>0)
    {
        printf("\nWrong position\n");
        return;
    }

    printf("Enter the element to be inserted: ");
    int element;
    scanf("%d",&element);

    struct node *newnode = getnewnode(element);

    struct node* cur = head;
    struct node* prev = NULL;

    int c = 1;
    while(cur != NULL)
    {
        if(c == pos)
        {
            if(c == 1)
            {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                count = count + 1;
                break;
            }

            if(c == count)
            {
                cur->next = newnode;
                newnode->prev = cur;
                count = count + 1;
                break;
            }

            else
            {
            prev->next = newnode;
            newnode->next = cur;
            cur->prev = newnode;
            newnode->prev = prev;
            count = count + 1;
            }



        }
        else
        {
            prev = cur;
            cur = cur->next;
            c = c + 1;

        }

    }
}

struct node* getnewnode(int element)
{
    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->data = element;
    newnode->next = NULL;
    newnode->prev = NULL;
}
