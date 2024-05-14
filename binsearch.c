#include <stdio.h>
#include <stdlib.h>

static const int MAX_NUMBER = 100;

int binarySearchIterative(int const *array, size_t size, const int searched, size_t * const steps);
int binarySearchRecursive(int const *array, size_t size, const int searched, size_t left, size_t right, size_t * const steps);
int linearSearch(int const *array, size_t size, const int searched, size_t * const steps);

int main () {
    // fill the numbers from 0 to 99 sorted in the numbers array
    int numbers[MAX_NUMBER];
    for (int i = MAX_NUMBER; i; --i) {
        numbers[MAX_NUMBER - i] = MAX_NUMBER - i;
    }

    int searched;
    printf("Please input a number to search from 0 to %d \n", MAX_NUMBER - 1);
    scanf("%d", &searched);
    if (searched > MAX_NUMBER - 1 || searched < 0) {
        printf("Invalid number.\n");
        return 0;
    }

    size_t stepsBinarySearchInteractive = 0;
    int indexOfSearchedBinarySearchInteractive;
    indexOfSearchedBinarySearchInteractive = binarySearchIterative(numbers, (size_t) MAX_NUMBER, searched, &stepsBinarySearchInteractive);
    indexOfSearchedBinarySearchInteractive != -1 ?
        printf("BinarySearchInteractive:\n found on index: %d, found with %d steps \n", indexOfSearchedBinarySearchInteractive, (int) stepsBinarySearchInteractive) : 
        printf("number %d not found. \n", searched);

    size_t stepsBinarySearchRecursive = 0;
    int indexOfSearchedBinarySearchRecursive;
    indexOfSearchedBinarySearchRecursive = binarySearchRecursive(numbers, (size_t) MAX_NUMBER, searched, 0, MAX_NUMBER, &stepsBinarySearchRecursive);
    indexOfSearchedBinarySearchRecursive != -1 ?
        printf("BinarySearchRecursive:\n found on index: %d, found with %d steps \n", indexOfSearchedBinarySearchRecursive, (int) stepsBinarySearchRecursive) : 
        printf("number %d not found. \n", searched);

    size_t stepsLinearSearch = 0;
    int indexOfSearchedLinearSearch;
    indexOfSearchedLinearSearch = linearSearch(numbers, (size_t) MAX_NUMBER, searched, &stepsLinearSearch);
    indexOfSearchedLinearSearch != -1 ?
        printf("LinearSearch:\n found on index: %d, found with %d steps \n", indexOfSearchedLinearSearch, (int) stepsLinearSearch) : 
        printf("number %d not found. \n", searched);

    return 0;
}

int binarySearchIterative(int const *array, size_t size, const int searched, size_t * const steps) {
    int l = 0, r = size, mid;
    int indexOfSearched = -1;
    for (*steps = 1; r >= l; ++*steps) {
        mid = l / 2 + r / 2;
        int current = array[mid];
        if (current == searched) {
            indexOfSearched = mid;
            break;
        } else if (current > searched) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return indexOfSearched;
}

int binarySearchRecursive(int const *array, size_t size, const int searched, size_t left, size_t right, size_t * const steps) {
    if (right < left) {
        return -1;
    }
    
    ++*steps;
    size_t mid = (left + right) / 2;
    int current = array[mid]; 

    if (current == searched) {
        return mid;
    } else if (current > searched) {
        return binarySearchRecursive(array, size, searched, left, mid, steps);
    } else {
        return binarySearchRecursive(array, size, searched, mid + 1, right, steps);
    }
}

int linearSearch(int const *array, size_t size, const int searched, size_t * const steps) {
    *steps = 1;
    for (int i = 0; i < size; ++i) {
        int current = array[i];
        if (current > searched) {
            return -1;
        } else if (current == searched) {
            return i;
        } else { // current < searched
            ++*steps;
        }
    }
}

