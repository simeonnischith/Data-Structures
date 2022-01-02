# include <stdio.h>
# define max 100
int n;
int arr [max];
int ls();
void main()
{

    printf("Enter the number of elements in the array: ");
    int n = 0;
    scanf("%d",&n);

    int i = 0;
    for(i=0;i<n;i++)
    {
        printf("Enter the element at [%d]",i);
        scanf("%d",&arr[i]);        
    }

    printf("Enter the search element: ");
    int s;
    scanf("%d",&s);

    int pos = ls(arr, n, s);
    
    if(pos!=-1)
        printf("\nPOSITION: %d\n", pos);
    else
        printf("\nElement not found\n");

}

int ls(int arr[], int n,int s)
{

    int i = 0;

    for(i=0;i<n;i++)
    {
        if(arr[i] == s)
            return i;
    }

    return  -1;

}