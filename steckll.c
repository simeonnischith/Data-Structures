# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *top = NULL;

void push();
void pop();
void prints();

void main()
{
    int c;

    do
    {
        printf("1. Push\n2. Pop\n3. Print Stack\n4. Exit\nEnter your choice: ");
        scanf("%d",&c);

        switch(c)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: prints(); break;

        }


    }
    while(c!=4);

}

void push()
{
    printf("\nEnter the element to be pushed: ");
    int element;
    scanf("%d",&element);


    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->data = element;
    newnode->next = NULL;

    if(top == NULL)
    {
        top = newnode;
        printf("\n%d pushed\n",element);

        return;
    }


    newnode->next = top;
    top = newnode;
    
    printf("\n%d pushed\n",element);

}

void prints()
{
    if(top == NULL)
    {
        printf("\nStack underflow\n");
        return;
    }
    struct node* temp = top;
    while(temp != NULL)
    {
        printf("\n%d\n",temp->data);

        temp = temp->next;
    }


}

void pop()
{
    if(top == NULL)
    {
        printf("\nStack underflow\n");
        return;
    }

    if(top->next == NULL)
    {
        printf("\n%d popped\n",top->data);

        top = NULL;
        return;
    }
    printf("\n%d popped\n",top->data);

    top = top->next;

}
