#include <stdio.h>
void accept(int n,int arr[])
{
  //accept element into Array
  int i=0;
  printf("\nEnter array elements:\n");


  for(i=0;i<n;i++)
  {printf("Element [%d] : ",(i+1));
   scanf("%d",&arr[i]);}

   return ;
}

void par(int n,int arr[])
{
  //print array
  int i=0;

  for(i=0;i<n;i++)
  printf("%d ",arr[i]);

  return ;
}
void swap(int *x,int *y)
{
  //swap numbers
  int t=*x;
  *x=*y;
  *y=t;
return ;
}

//bubble sort
void bsort(int n,int arr[])
{
int i=0,j=0,t=0;

for(i=0;i<n;i++)
{
  for(j=0;j<(n-i-1);j++)
  {
    //if adjacent elements arent equal, smaller element is shifted to the start
    if(arr[j]>arr[j+1])
    swap(&arr[j],&arr[j+1]);
  }
}

  return;
}
void isort(int n,int arr[])
{
int i=0,j=0;

for(i=1;i<n;i++)
{
  for(j=i;j>=0;j--)
  {if(arr[j]<arr[j-1])
  swap(&arr[j],&arr[j-1]);}
}

  return;
}
void ssort(int n,int arr[])
{
  int i=0,j=0,pos=0,min=arr[0];

for(i=0;i<n;i++)
{
  //initialise smallest element and index
  pos=i;
  min=arr[i];

//find the smallest element in unsorted-sub-array
  for(j=i;j<n;j++)
  {
    if(arr[j]<min)
    {min=arr[j]; pos=j;}
  }
//swap
  swap(&arr[i],&arr[pos]);

}

  return;
}

int ls(int n,int arr[],int s)
{
  int i=0;

  for(i=0;i<n;i++)
  {
    if(arr[i]==s)
    return (1+i);
  }

return 0;
  }

int bs(int n,int arr[],int s)
{
  int i=0,f=0,l=n-1,m=0;

  while(f<=l)
  {
  m=(f+l)/2;

  if(arr[m]<s)
  f=m+1;
  else
  {if(arr[m]==s)
  return (1+m);
  else
  l=m-1;}
  }

return 0;}
int main()
{
//array size from user
int n=0;
printf("Enter number of array elements: ");
scanf("%d",&n);

//create array with above size
int arr[n];

//accept elements into array
accept(n,arr);

int res;
printf("\nSort Technique:\n1.Bubble Sort 2.Selection Sort 3.Insertion Sort\n");
scanf("%d",&res);

printf("Pre-Sorted Array:\n");
par(n,arr);

if(res==1)
bsort(n,arr);

if(res==2)
ssort(n,arr);

if(res==3)
isort(n,arr);

printf("\nSorted Array: \n");
par(n,arr);

//searching
int search;
printf("\nEnter element to be searched: ");
scanf("%d",&search);



printf("\nSearch Technique:\n1.Linear Search 2.Binary Search\n");
scanf("%d",&res);

if(res==1)
res=ls(n,arr,search);

if(res==2)
res=bs(n,arr,search);

if(res!=0)
printf("\n%d Element found at %d th position ",search,(res));
else
printf("\n%d Element not found",search);

return 0; }
