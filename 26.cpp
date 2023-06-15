#include<stdio.h>
#include<string.h>

int main()
{
    char source[100];
    char destination[100];
    int i, d;

    printf("Enter a string: ");
    scanf("%s", source);

    d = strlen(source);

    for(i = 0; i < d; i++)
    {
        destination[i] = source[i];
    }

    destination[i] = '\0';

    printf("Copied string: %s", destination);

    return 0;
}
