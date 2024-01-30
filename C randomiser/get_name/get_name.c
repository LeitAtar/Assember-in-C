#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_NAMES 30

const char* get_name();
int  compare(const char *str1, const char *str2);
char nameList[30][20];

int main() {
    int i, j;

    printf("Please insert %d different names, separated by Enter:\n", MAX_NAMES);

    for (i = 0; i < MAX_NAMES; ++i) {
        scanf("%s", nameList[i]);

        for (j = 0; j < i; ++j) {
            if (compare(nameList[i], nameList[j]) == 0) {
                printf("The program has stopped because of a duplicate name.\n");
                return 1;
            }
        }
    }

    printf("\nThe program has received the following names:\n");

    for (i = 0; i < MAX_NAMES; ++i) {
        printf("%s\n", nameList[i]);
    }

    printf("Below are 10 random names from the list: \n");

    for (i = 0; i < 10; ++i) {
        printf("%s\n", get_name());
    }

    return 0;
}
const char* get_name() {
    int randomNumber = rand() % MAX_NAMES;
    return nameList[randomNumber];
}

int compare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        int diff = toupper(*str1) - toupper(*str2);
        if (diff != 0) {
            return diff;
        }

        ++str1;
        ++str2;
    }

    return toupper(*str1) - toupper(*str2);
}
