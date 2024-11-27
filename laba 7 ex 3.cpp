#include <stdio.h>

// Функция проверки ввода числа
void getValidInput(int* value) {
    while (1) {
        if (scanf_s("%d", value) != 1) {
            while (getchar() != '\n'); // Очистка ввода
            printf("Error, try again!\n");
        }
        else {
            char ch;
            if (scanf_s("%c", &ch, 1) == 1 && ch != '\n') {
                while (getchar() != '\n'); // Очистка ввода
                printf("Error!! Enter again: ");
            }
            else {
                break;
            }
        }
    }
}

// Функция для нахождения длины самого короткого слова в строке
int shortestWordLength(const char* str) {
    int minLength = 1000, currentLength = 0, i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            currentLength++;
        }
        else if (currentLength > 0) {
            if (currentLength < minLength) {
                minLength = currentLength;
            }
            currentLength = 0;
        }
        i++;
    }

    // Проверка последнего слова
    if (currentLength > 0 && currentLength < minLength) {
        minLength = currentLength;
    }

    return minLength;
}

// Функция слияния двух массивов строк
void merge(char arr[][100], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    char leftArr[size1][100], rightArr[size2][100];

    // Копируем строки в два подмассива
    for (int i = 0; i < size1; i++) {
        for (int j = 0; arr[left + i][j] != '\0'; j++) {
            leftArr[i][j] = arr[left + i][j];
            leftArr[i][j + 1] = '\0';
        }
    }
    for (int i = 0; i < size2; i++) {
        for (int j = 0; arr[mid + 1 + i][j] != '\0'; j++) {
            rightArr[i][j] = arr[mid + 1 + i][j];
            rightArr[i][j + 1] = '\0';
        }
    }

    // Слияние обратно в основной массив
    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (shortestWordLength(leftArr[i]) <= shortestWordLength(rightArr[j])) {
            int m = 0;
            while (leftArr[i][m] != '\0') {
                arr[k][m] = leftArr[i][m];
                m++;
            }
            arr[k][m] = '\0';
            i++;
        }
        else {
            int m = 0;
            while (rightArr[j][m] != '\0') {
                arr[k][m] = rightArr[j][m];
                m++;
            }
            arr[k][m] = '\0';
            j++;
        }
        k++;
    }

    // Копируем оставшиеся строки
    while (i < size1) {
        int m = 0;
        while (leftArr[i][m] != '\0') {
            arr[k][m] = leftArr[i][m];
            m++;
        }
        arr[k][m] = '\0';
        i++;
        k++;
    }

    while (j < size2) {
        int m = 0;
        while (rightArr[j][m] != '\0') {
            arr[k][m] = rightArr[j][m];
            m++;
        }
        arr[k][m] = '\0';
        j++;
        k++;
    }
}

// Функция сортировки слиянием
void mergeSort(char arr[][100], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Основная функция
int main() {
    int n;

    // Ввод числа строк с проверкой
    printf("Enter the number of strings: ");
    getValidInput(&n);

    // Массив строк
    char strings[n][100];
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        int j = 0;
        while ((strings[i][j] = getchar()) != '\n') {
            if (strings[i][j] != '\n') {
                j++;
            }
        }
        strings[i][j] = '\0';
    }

    // Сортировка массива
    mergeSort(strings, 0, n - 1);

    // Вывод результата
    printf("\nSorted strings by shortest word length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}