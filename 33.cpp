#include<stdio.h>
#include<string.h>

int main()
{
    char str[40];
    int d,count=0;

    printf("Enter the string: ");
    count++;
    scanf("%s",&str);
    count++;

    d=strlen(str);

    printf("The length of the entered string is: %d",d);
    count++;

    printf("\n");

    printf("The time complexity is: %d",count);
    return 0;
}
