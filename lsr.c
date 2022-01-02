# include <stdio.h>
# define max 100
int arr[max];

int lsr();
void main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int i = 0;
    for(i=0;i<n;i++)
    {
        printf("Enter the element at [%d]: ",i);
        scanf("%d",&arr[i]);
    }

    int s;
    printf("Enter the element to be searched: ");
    scanf("%d",&s);

    int pos = lsr(arr, n, s, 0);
    printf("\nPosition: %d\n",pos);
}

int lsr(int arr[], int n, int s, int index)
{
    if(index<n)
    {
        if(arr[index]==s)
            return index;
        else
            return lsr(arr, n, s, index+1);
    }
    else
    {
        return -1;
    }
}


