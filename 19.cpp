//palindrome checking//
#include <stdio.h>
#include <string.h>

int main()
{
    char str[40];
    int i, j, d;

    printf("Enter the string: ");
    scanf("%s", str);

    d = strlen(str);
    int palindrome = 1;

    for (i = 0, j = d - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
    {
        printf("Entered string is a palindrome.\n");
    }
    else
    {
        printf("Entered string is not a palindrome.\n");
    }

    return 0;
}
