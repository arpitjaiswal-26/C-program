 #include <stdio.h>

// Function to calculate length of a string
int myStrlen(char str[]) {
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') // stop at newline or null
        len++;
    return len;
}

// Function to copy one string to another
void myStrcpy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0' && src[i] != '\n') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Null terminate destination string
}

// Function to concatenate two strings
void myStrcat(char dest[], char src[]) {
    int i = 0, j = 0;

    // Move i to end of dest string
    while (dest[i] != '\0')
        i++;

    // Copy src into dest starting from end
    while (src[j] != '\0' && src[j] != '\n') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0'; // Null terminate final string
}

int main() {
    char str1[100], str2[100], copy[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // strlen()
    printf("\nLength of first string = %d", myStrlen(str1));
    printf("\nLength of second string = %d", myStrlen(str2));

    // strcpy()
    myStrcpy(copy, str1);
    printf("\n\nCopied string (str1 → copy): %s", copy);

    // strcat()
    myStrcat(str1, str2);
    printf("\nConcatenated string (str1 + str2): %s\n", str1);

    return 0;
}
