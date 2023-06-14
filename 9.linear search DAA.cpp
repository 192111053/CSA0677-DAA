#include<stdio.h>
int main()
{
    int arr[100],n,key,count=0;
    printf("Enter the number of elements: ");
    count++;
    scanf("%d",&n);
    count++;
    printf("Enter the elements in array: ");
    count++;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        count++;
    }
    printf("Enter the elements to search: ");
    count++;
    scanf("%d",&key);
    count++;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            printf("The searched elements %d is present at %dth location",key,i);
            count++;
        }
    }
    printf("\n");
    count++;
    printf("The total number of count is: %d",count);
}
