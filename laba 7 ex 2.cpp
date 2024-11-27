#include <stdio.h>

// Функция для проверки корректного ввода целочисленного значения
void getValidInput(int* value) {
    while (1) {
        if (scanf_s("%d", value) != 1) {
            while (getchar() != '\n');
            printf("Error, try again!\n");
        }
        else {
            char ch;
            if (scanf("%c", &ch) == 1 && ch != '\n') {
                while (getchar() != '\n');
                printf("Error!! Enter again: ");
            }
            else {
                break;
            }
        }
    }
}

// Функция для вычисления длины строки
int getStringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Функция для проверки, содержится ли подстрока S0 в строке S
int findSubstring(const char* S, const char* S0) {
    int lenS = getStringLength(S);
    int lenS0 = getStringLength(S0);

    if (lenS0 == 0) return 0; // Если подстрока пустая, вернуть 0
    if (lenS0 > lenS) return -1; // Если длина S0 больше S, сразу -1

    for (int i = 0; i <= lenS - lenS0; i++) {
        int j = 0;
        while (j < lenS0 && S[i + j] == S0[j]) {
            j++;
        }
        if (j == lenS0) {
            return i; // Возвратить индекс начала совпадения
        }
    }
    return -1; // Если совпадения нет
}

// Основная программа
int main() {
    char S[100], S0[100];

    printf("Enter the main string S: ");
    scanf_s("%99s", S); // Ввод строки S с ограничением на длину

    printf("Enter the substring S0: ");
    scanf_s("%99s", S0); // Ввод строки S0 с ограничением на длину

    int position = findSubstring(S, S0);
    if (position == -1) {
        printf("The substring S0 is not found in S.\n");
    }
    else {
        printf("The substring S0 is found at position: %d\n", position);
    }

    return 0;
}
