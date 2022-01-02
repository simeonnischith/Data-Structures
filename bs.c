# include <stdio.h>
# define max 100
int arr [max];

int bs();
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

    int pos = bs(arr, n, s);

    if(pos!=-1)
        printf("\nPosition: %d\n",pos);
    else
        printf("\nElement not found\n");

}

int bs(int arr[], int n, int s)
{
    int l = 0;
    int r = n-1;

 

    while(l<=r)
    {

        int m = (l+r)/2;

        if(arr[m]==s)
            return m;
        else if(arr[m]<s)
            l = m+1;
        else 
            r = m-1;
    }

    return -1;
}

