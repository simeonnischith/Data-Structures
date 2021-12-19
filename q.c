#include <stdio.h>


#define max 10
int queue [max];
int front = -1;
int rear = -1;

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
    if(rear == max-1)
    {
        printf("\nQueue is full\n" );
        return;
    }

    printf("\nEnter the element to be inserted: ");
    int element;
    scanf("%d",&element);


    queue[++rear]=element;

    if(rear == 0)
    {
        front = 0;
    }


}

void delete()
{
    if(front>rear || rear == -1)
    {
        printf("\nQueue is empty\n" );
        return;

    }

    printf("\n%d deleted \n",queue[front++]);

}

void display()
{
    if(rear == -1 || front>rear)
    {
        printf("\nQueue is empty\n");
        return;
    }

    int i = front;

    printf("\n");
    for(;i<=rear;i++)
    {
        printf(" %d ",queue[i]);
    }


        printf("\n");
}
