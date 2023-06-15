//largest number of array//

#include<stdio.h>

int main()
{
    int arr[20];

    int size,max_num,count=0;

    printf("Enter the size of the array: ");
    count++;
    scanf("%d",&size);
    count++;

    printf("Enter the elements in the array: \n");
    count++;


    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
        count++;
    }

    printf("The entered elements are:\n");
    count++;

     for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
        count++;
    }

    max_num=arr[0];
    for(int i=0;i<size;i++)
    {
        if(max_num<arr[i])
        {
            max_num=arr[i];
            count++;
        }
    }
    printf("\n");

    printf("The maximum element in the array is: %d",max_num);
    count++;

    printf("\n");
    count++;

    printf("The time complexity is: %d",count);
    
    return 0;
}
