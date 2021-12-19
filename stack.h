#include <stdio.h>

//STACK - ARRAY IMPLEMENTATION

int top=-1;
int size=100;
int stack [100];

void push(int element)
{

if(top==(size-1))
{
  printf("\nSTACK OVERFLOW\n");
}

else
{

stack[++top]=element;
}

}

void pop()
{

if(top==-1)
{
printf("\nSTACK UNDERFLOW\n");
}

else
{
int element;
element=stack[top--];

}

}

void display()
{
printf("\n");
if(top==-1)
{
printf("EMPTY");
}

int i;
for(i=top;i>=0;i--)
printf("%d\n",stack[i]);

printf("\n\n");

}



int main()
{

return 0;
}
