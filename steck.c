# include <stdio.h>
# include <stdlib.h>

int stack[100];
int max = 100;
int top = -1;

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


    if(top == 99)
    {
        printf("\nStack overflow\n");
        return;
    }

    printf("\nEnter the element to be pushed: ");
    int element;
    scanf("%d",&element);

    stack[++top] = element;

    printf("\n%d pushed in stack\n",element);
    return;

}

void pop()
{
    if(top == -1)
    {
        printf("\nStack underflow\n");
        return;
    }

    int element = stack[top--];
    printf("\n%d popped\n",element);

}

void prints()
{

    if(top == -1)
    {
        printf("\nStack underflow\n");
        return;
    }

    int i;



    for(i=top;i>=0;i--)
    {
        printf("\n%d\n",stack[i]);

    }
}
