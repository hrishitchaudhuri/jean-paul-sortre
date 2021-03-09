#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "utils.h"

/*
 * PROBLEM STATEMENT: Implement selection sort, bubble sort, quick sort and merge sort 
 * to sort numbers in non-decreasing order.
 */

// * FILE WRITE FUNCTIONS.

int fwrite_out_time(char *filename, double time) {
    FILE *fp;

    fp = fopen(filename, "a");
    fprintf(fp, "%d, %lf\n", ARRAY_MAX_SIZE, time);

    fclose(fp);
    return 0;
}

int fwrite_out_comp(char *filename, long int cmp) {
    FILE *fp;

    fp = fopen(filename, "a");
    fprintf(fp, "%d, %ld\n", ARRAY_MAX_SIZE, cmp);

    fclose(fp);
    return 0;
}

// * HELPER FUNCTIONS.

void swap(int *arr, int i, int j) {
    register int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void merge_inc(int *arr, int *oth, int *i, int *j) {
    oth[(*i)++] = arr[*j];
    (*j)++;
}

void merge(int *arr, int low, int mid, int high, const int ARR_SIZE) {
    int i, j, k;
    int oth[ARR_SIZE];

    i = low; j = mid + 1; k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            merge_inc(arr, oth, &k, &i);

        else
            merge_inc(arr, oth, &k, &j);
    
        GLOBAL_COMP_COUNT++;
    }
    
    while (i <= mid) {
        merge_inc(arr, oth, &k, &i);
        GLOBAL_COMP_COUNT++;
    }

    while (j <= high) {
        merge_inc(arr, oth, &k, &j);
        GLOBAL_COMP_COUNT++;
    }

    j = low;
    for (i = 0; i < k; i++)
        arr[j++] = oth[i];
}

int qs_partition(int *arr, int low, int high, const int ARR_SIZE) {
    register int pivot, i, j;

    pivot = arr[low]; i = low + 1; j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
            GLOBAL_COMP_COUNT++;
        }

        while (j > low && arr[j] >= pivot) {
            j--;
            GLOBAL_COMP_COUNT++;
        }

        if (i < j)
            swap(arr, i, j);
        
        GLOBAL_COMP_COUNT++;
    }

    if (j != low) {
        arr[low] = arr[j];
        arr[j] = pivot;
    }
    
    GLOBAL_COMP_COUNT++;

    return j;
}


// * NOTE: Iterative sorting functions will follow the prototype `void <func_name>(int *, int);` *
// *       Recursive sorting functions will follow the prototype `void <func_name>(int *, int, int, const int);` *

void sel_sort(int *arr, int sz) {
    register int i, j;
    int min_pointer;

    for (i = 0; i < (sz-1); i++) {
        min_pointer = i;
        for (j = min_pointer + 1; j < sz; j++) {
            if (arr[j] < arr[min_pointer])
                min_pointer = j;
            GLOBAL_COMP_COUNT++;
        }

        if (min_pointer != i)
            swap(arr, min_pointer, i);
        GLOBAL_COMP_COUNT++;
    }
}

void bub_sort(int *arr, int sz) {
    register int i, j;
    
    for (i = 0; i < (sz - 1); i++)
        for (j = 0; j < (sz - i - 1); j++) {
            if (arr[j] > arr[j+1])
                swap(arr, j, j + 1);
        
            GLOBAL_COMP_COUNT++;
        }
}

void mrg_sort(int *arr, int low, int high, const int ARR_SIZE) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        
        mrg_sort(arr, low, mid, ARR_SIZE);
        mrg_sort(arr, mid + 1, high, ARR_SIZE);

        merge(arr, low, mid, high, ARR_SIZE);
    }
    GLOBAL_COMP_COUNT++;
}

void qck_sort(int *arr, int low, int high, const int ARR_SIZE) {
    register int j;

    if (low < high) {
        j = qs_partition(arr, low, high, ARR_SIZE);
        
        qck_sort(arr, low, j - 1, ARR_SIZE);
        qck_sort(arr, j + 1, high, ARR_SIZE);
    }
    GLOBAL_COMP_COUNT++;
}

// * TIMING FUNCTION. 
void sort_with_time(char SORT_TYPE, int *ARR, int *ARGS) {
    clock_t start, end;

    switch(SORT_TYPE) {
        case 's':
            printf("[INFO] Starting clock.\n");
            start = clock();
            sel_sort(ARR, ARGS[0]);
            end = clock();
            printf("[INFO] Stopping clock.\n");

            fwrite_out_time("../out/sel_sort_time.txt", (double) (end - start) / CLOCKS_PER_SEC);
            fwrite_out_comp("../out/sel_sort_comp.txt", GLOBAL_COMP_COUNT);
            break;

        case 'b':
            printf("[INFO] Starting clock.\n");
            start = clock();
            bub_sort(ARR, ARGS[0]);
            end = clock();
            printf("[INFO] Stopping clock.\n");

            fwrite_out_time("../out/bub_sort_time.txt", (double) (end - start) / CLOCKS_PER_SEC);
            fwrite_out_comp("../out/bub_sort_comp.txt", GLOBAL_COMP_COUNT);
            break;

        case 'm':
            printf("[INFO] Starting clock.\n");
            start = clock();
            mrg_sort(ARR, ARGS[0], ARGS[1], ARGS[2]);
            end = clock();
            printf("[INFO] Stopping clock.\n");

            fwrite_out_time("../out/mrg_sort_time.txt", (double) (end - start) / CLOCKS_PER_SEC);
            fwrite_out_comp("../out/mrg_sort_comp.txt", GLOBAL_COMP_COUNT);
            break;

        case 'q':
            printf("[INFO] Starting clock.\n");
            start = clock();
            qck_sort(ARR, ARGS[0], ARGS[1], ARGS[2]);
            end = clock();
            printf("[INFO] Stopping clock.\n");
            
            fwrite_out_time("../out/qck_sort_time.txt", (double) (end - start) / CLOCKS_PER_SEC);
            fwrite_out_comp("../out/qck_sort_comp.txt", GLOBAL_COMP_COUNT);
            break;

        default:
            printf("\033[0;31m>> [ERR] Invalid sort. \n\033[0m");
            exit(0);
    }
    printf("%lf \t %lf \n", (double) end, (double) start);
    printf("%lf SECONDS. \n", (double) (end - start) / CLOCKS_PER_SEC);
    printf("%ld COMPARISONS MADE. \n", GLOBAL_COMP_COUNT);
}

// * ARRAY INITIALIZATION.

void arr_init(int *arr, int sz) {
    for (register int i = 0; i < ARRAY_MAX_SIZE; i++)
        arr[i] = rand();

    printf("[INFO] Array declared.\n");

    GLOBAL_COMP_COUNT = 0;
}