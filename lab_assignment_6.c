#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2; // To avoid potential integer overflow
    if (numbers[mid] == value)
        return mid;

    if (numbers[mid] < value)
        return search(numbers, mid + 1, high, value);
    else
        return search(numbers, low, mid - 1, value);
}

void printArray(int numbers[], int sz) {
    int i;
    printf("Number array: ");
    for (i = 0; i < sz; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void) {
    int i, numInputs;
    int value, index;
    int *numArray = NULL;
    int countOfNums;
    FILE *inFile = fopen("input.txt", "r");

    if (inFile == NULL) {
        printf("Failed to open input.txt.\n");
        return 1;
    }

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *)malloc(countOfNums * sizeof(int));
        if (numArray == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile, " %d", &value);
            numArray[i] = value;
        }

        printArray(numArray, countOfNums);
        fscanf(inFile, "\n %d", &value);
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        } else {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
