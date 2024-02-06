```markdown
# C Programming - Search Algorithms

This repository provides C programming examples for basic search algorithms, including linear search and binary search.

## Contents

1. [Linear Search](#1-linear-search)
2. [Binary Search](#2-binary-search)
3. [Choosing the Best Search Algorithm](#3-choosing-the-best-search-algorithm)

## 1. Linear Search

Linear search, also known as sequential search, is a simple algorithm that checks each element in a collection one by one until the target is found or the entire collection has been searched.

### Code Example

```c
#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

```

## 2. Binary Search

Binary search is an efficient algorithm for searching in sorted arrays. It works by repeatedly dividing the search interval in half and comparing the target value to the middle element.

### Code Example

```c
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index if the target is found
        }

        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

```

## 3. Choosing the Best Search Algorithm

The choice between linear search and binary search depends on the specific requirements and characteristics of the data. Binary search is generally more efficient for sorted data, while linear search is suitable for unsorted data or small datasets.

Consider factors such as data structure, data size, and search frequency to choose the most appropriate algorithm for your needs.
