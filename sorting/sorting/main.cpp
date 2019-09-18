//
//  main.cpp
//  sorting
//
//  Created by Saransh Kalra on 11/14/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include <iostream>

using namespace std;

void print_arr (int *arr, int size) {
    cout << "{" << arr[0];
    for (int i = 1; i < size; i++) {
        cout << "," << arr[i];
    }
    cout << "}"<<endl;
}

void selection_sort (int *arr, int size) {
    int min, temp;
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int *arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 1; j < size - i; j++) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr [j - 1] = temp;
            }
        }
    }
}

void insertion_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[min];
        for (int j = min; j > i; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i] = temp;
    }
}

void merge(int *arr, int *larr, int *rarr, int size) {
    int i = 0, j = 0, k = 0;
    while (i < size / 2 && j < size - size / 2) {
        if (larr[i] < rarr[j]) {
            arr[k] = larr[i];
            i++;
        }
        else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    if (i == size / 2) {
        while (k < size) {
            arr[k] = rarr[j];
            k++;
            j++;
        }
    }
    else {
        while (k < size) {
            arr[k] = larr[i];
            k++;
            i++;
        }
    }
}

void merge_sort(int *arr, int size) {
    if (size > 1) {
        int lsize = size / 2;
        int *larr = new int[lsize];
        int *rarr = new int[size - lsize];
        for (int i = 0; i< lsize; i++) {
            larr[i] = arr[i];
        }
        for (int i = lsize; i < size; i++) {
            rarr[i - lsize] = arr[i];
        }
        merge_sort(larr, lsize);
        merge_sort(rarr, size - lsize);
        merge(arr, larr, rarr, size);
        delete larr;
        delete rarr;
    }
}

int pivot(int *arr, int lo, int hi) {
    int pvt_num = arr[hi];
    int temp, i = lo;
    for( int j = i; j < hi; j++) {
        if (arr[j] < pvt_num) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
    temp = arr[i];
    arr[i] = arr[hi];
    arr[hi] = temp;
    return i;
}

void quick_sort_helper(int *arr, int lo, int hi) {
    if(lo <= hi) {
        int pvt_index = pivot(arr, lo, hi);
        quick_sort_helper(arr, lo, pvt_index - 1);
        quick_sort_helper(arr, pvt_index + 1, hi);
    }
}

void quick_sort(int *arr, int size) {
    quick_sort_helper(arr, 0 , size - 1);
}

int main() {
    
    int arr[] = {42, 68, 12, 2, 19, 100};
    print_arr(arr, 6);
    quick_sort(arr, 6);
    print_arr(arr, 6);
    
    return 0;
}
