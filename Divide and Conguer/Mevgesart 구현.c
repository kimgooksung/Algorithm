#include <stdio.h>

int arr[8] = {8, 2, 5, 7, 3, 1, 6, 4};
int sorted[8] = {0, 3};

void merge(int arr[], int s, int mid, int e);

void mergeSort(int arr[], int s, int e) {
    if (s < e) {
        int mid = (s + e) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

void merge(int arr[], int s, int mid, int e) {
    int temp[e - s + 1];
    int i = s;
    int j = mid + 1;
    int k = 0; 

    while (i <= mid && j <= e) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= e) {
        temp[k++] = arr[j++];
    }

    for (int a = s, b = 0; a <= e; a++, b++) {
        arr[a] = temp[b];
    }
}

int main() {
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}