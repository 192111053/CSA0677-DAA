#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a substring is present in a string
bool isSubstring(char str[], char substr[]) {
    int n = strlen(str);
    int m = strlen(substr);

    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check if the current position in the string matches the substring
        for (j = 0; j < m; j++) {
            if (str[i + j] != substr[j])
                break;
        }

        // If the entire substring is found, return true
        if (j == m)
            return true;
    }

    // Substring not found
    return false;
}

// Example usage
int main() {
    char str[100];
    char substr[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter a substring to search for: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0'; // Remove trailing newline character

    if (isSubstring(str, substr))
        printf("Substring found in the string.\n");
    else
        printf("Substring not found in the string.\n");

    return 0;
}
