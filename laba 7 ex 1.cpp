#include<stdio.h>


int findCount(const char* string) {
    int count = 0;
    int currentWord = 0;

    while (*string != '\0') {
        if (*string >= 'A' && *string <= 'Z' || *string >= 'a' && *string <= 'z') {
            currentWord++;
        }
        else {
            if (currentWord > 0 && currentWord % 2 == 0) {
                count++;
            }
            currentWord = 0;
        }
        string++;
    }

    if (currentWord % 2 == 0 && currentWord > 0) {
        count++;
    }

    return count;
}



int main() {
    char string[] = "Hello worldd my name is Igorrrrrr";

    int count = findCount(string);
    printf(" count = %d", count);



}