//prime number//

#include<stdio.h>

int main()
{
    int i,num,count=0;
    int fact_count=0;

    printf("Enter the number: ");
    count++;
    scanf("%d",&num);
    count++;

    for(i=1;i<=num;i++)
    {
        if(num%i==0)
        {
            fact_count++;
            count++;
        }
    }
    if(fact_count>2)
    {
        printf("The number %d is not prime number",num);
        count++;
    }
    else{
        printf("The number %d is a prime number",num);
        count++;
    }
    printf("\n");
    count++;

    printf("The time complexity is: %d",count);
    return 0;

}
