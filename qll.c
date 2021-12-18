# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* front = NULL;

void insert();
void delete();
void display();

void main()
{
    int c;

    do
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d",&c);

        switch(c)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
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

    if(front == NULL)
    {
        front = newnode;
        return;
    }

    struct node* temp = front;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    printf("\n");

}

void delete()
{
    if(front == NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\n%d deleted\n",front->data);
    if(front->next == NULL)
    {
        front = NULL;
        free(front);
        return;
    }
    struct node* temp = front;
    front = front->next;
    free(temp);

    printf("\n");
}

void display()
{
    if(front == NULL)
    {
        printf("\nQueue is empty\n");
        return;

    }

    printf("\n");

    struct node* temp = front;
    while(temp != NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
