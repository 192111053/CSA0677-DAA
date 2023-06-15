#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gcd(int a, int b);

int main()
{
    int num1, num2;
    int count=0;

    printf("Enter teh two numbers: ");
    count++;

    scanf("%d %d",&num1,&num2);
    count++;

    int result = gcd(num1,num2);

    printf("Gcd of %d and %d is %d\n",num1,num2,result);
    count++;

    printf("Time complexity is: %d",count);

    return 0;
}

int gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    return gcd(b%a,a);
}
