# include <stdio.h>
# define max 100
int arr [max];

int bsr();
void main()
{
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d",&n);

    int i = 0;
    for(i=0;i<n;i++)
    {
        printf("Enter the element at [%d]: ",i);
        scanf("%d",&arr[i]);
    }

    int s;
    printf("Enter the element to be searched: ");
    scanf("%d", &s);

    int pos = bsr(arr, n, s, 0, n-1);

    if(pos!=-1)
        printf("\nPosition: %d\n",pos);
    else
        printf("\nElement not found\n");

}

int bsr(int arr[], int n, int s, int l, int r)
{
    if(l<=r)
    {
        int m = (l+r)/2;
        if(arr[m] == s)
            return m;
        else if(arr[m] > s)
            return bsr(arr, n, s, l, m-1);
        else
            return bsr(arr, n, s, m+1, r);    
    }
    else
    {
        return -1;
    }
}