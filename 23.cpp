//selectio sort//

#include<stdio.h>

int main()
{
    int n,position,swap,count=0;

    printf("Enter the size of the array: ");
    count++;

    scanf("%d",&n);
    count++;

    int arr[n];

    printf("Enter the elements of the array: \n");
    count++;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        count++;
    }
    
    printf("The entered array is: \n");
    count++;

    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        count++;
    }

    for(int i=0;i<n-1;i++)
    {
        position = i;

        for(int j = i+1; j<n;j++)
        {   
            if(arr[position]>arr[j])
            {
              position = j;
            }
        }

        if(position != i)
        {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }
    printf("\n");
    count++;

    printf("The sorted array is: \n");
    count++;

    for(int i=0;i<n;i++)
    {
      printf("%d\t",arr[i]);
      count++;
    }
    
    printf("\n");
    printf("The time complexity is: %d",count);

    return 0;



}
