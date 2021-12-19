#include <stdio.h>
int fib(int n)
{
  if(n==0)
  return 0;

  if(n==1||n==2)
  return 1;

  return(fib(n-1)+fib(n-2));

}
void toh(int n,char a,char c,char b)
{
if(n==1)
{printf("Move disc %d from %c to %c\n",n,a,c); return;}

toh(n-1,a,b,c);
printf("Move disc %d from %c to %c\n",n,a,c);
toh(n-1,b,c,a);

}
int main()
{
int n;
printf("Enter number of terms in Fibonacci sequence: ");
scanf("%d",&n);

int i=0;
for(i=0;i<n;i++)
{printf("%d, ",fib(i));}

printf("\n");
toh(3,'a','c','b');
return 0;}
