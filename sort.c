#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sort.h"

// Default Parameters
int elemsize;
int SORTMETHOD = BUBBLE;
int SORTDIRECTION = ASCENDING;

// Elements Swap Function
void swap(void * a1, void * a2, int elemsize) {
    void * tmp = malloc(elemsize);
    memcpy(tmp, a1, elemsize);
    memcpy(a1, a2, elemsize);
    memcpy(a2, tmp, elemsize);
    free(tmp);
}

// Bubble sort function
void bubble_sort(void * a, int n) {
    int r = n - 1, j, swapped;
    do {
        swapped = 0;
        for (j = 0; j < r; j++) {
            if (comp(a + (j + 1) * elemsize, a + j * elemsize)) {
                swap(a + j * elemsize, a + (j + 1) * elemsize, elemsize);
                swapped = 1;
            }
        }
        r--;
    } while (r > 0 && swapped);
}

// Insertion sort function
void insert_sort(void * a, int n) {
    int i, j;
    int * key = malloc(elemsize);
    for (i = 1; i < n; i++) {
        memcpy(key, a + i * elemsize, elemsize);
        for (j = i - 1; j >= 0; j--) {
            if (comp(key, a + j * elemsize)) {
                memcpy(a + (j + 1) * elemsize, a + j * elemsize, elemsize);
            } else break;
        }
        memcpy(a + (j + 1) * elemsize, key, elemsize);
    }
    free(key);
}

// Selection sort function
void selection_sort(void * a, int n) {
    int i, j, min;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (comp(a + j * elemsize, a + min * elemsize)) min = j;
        }
        if (min != i) swap(a + i * elemsize, a + min * elemsize, elemsize);
    }
}

// Comb sort function
void comb_sort(void * a, int n) {
    int i = 0, swapped = 1, p, r;
    p = n / 2;
    while (p > 1) {
        for (i = 0; i + p < n; i++) {
            if (comp(a + (i + p) * elemsize, a + i * elemsize))
                swap(a + i * elemsize, a + (i + p) * elemsize, elemsize);
        }
        p = p / 2;
    }
    r = n - 1;
    do {
        swapped = 0;
        for (i = 0; i < r; i++) {
            if (comp(a + (i + 1) * elemsize, a + i * elemsize)) {
                swap(a + i * elemsize, a + (i + 1) * elemsize, elemsize);
                swapped = 1;
            }
        }
        r--;
    } while (r > 0 && swapped);
}

// Shell sort function
void shell_sort(void * a, int n) {
    int i = 0, j, p;
    int * key = malloc(elemsize);
    p = n / 2;
    while (p > 0) {
        for (i = p; i < n; i++) {
            memcpy(key, a + i * elemsize, elemsize);
            for (j = i; j >= p; j -= p) {
                if (comp(key, a + (j - p) * elemsize)) {
                    memcpy(a + j * elemsize, a + (j - p) * elemsize, elemsize);
                } else break;
            }
            memcpy(a + j * elemsize, key, elemsize);
        }
        p = p / 2;
    }
    free(key);
}

// Separation algorithm
void partition(void * a, int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1;
    while (1) {
        do i++; while (comp(a + i * elemsize, a + l * elemsize));
        do j--; while (comp(a + l * elemsize, a + j * elemsize));
        if (i >= j) break;
        swap(a + i * elemsize, a + j * elemsize, elemsize);
    }
    partition(a, l, j);
    partition(a, j + 1, r);
}

// Quick sort function
void quick_sort(void * a, int n) {
    partition(a, 0, n - 1);
}

// Merge algorithm
void merge(void * a, int n, void * b) {
    int m = n / 2, k = 0, i = 0, j = m;
    for (k = 0; k < n; k++) {
        if (i > m - 1) {
            memcpy(b + k * elemsize, a + j * elemsize, elemsize);
            j++;
        } else {
            if (j == n) {
                memcpy(b + k * elemsize, a + i * elemsize, elemsize);
                i++;
            } else {
                if (comp(a + i * elemsize, a + j * elemsize)) {
                    memcpy(b + k * elemsize, a + i * elemsize, elemsize);
                    i++;
                } else {
                    memcpy(b + k * elemsize, a + j * elemsize, elemsize);
                    j++;
                }
            }
        }
    }
    for (k = 0; k < n; k++)
        memcpy(a + k * elemsize, b + k * elemsize, elemsize);
}

// Merge sort function
void merge_sort(void * a, int n, void * b) {
    if (n < 2) return;
    int i, m = n / 2;
    merge_sort(a, m, b);
    merge_sort(a + (m * elemsize), n - m, b + (m * elemsize));
    merge(a, n, b);
}

// Heap creation algorithm
void heap_down(void * a, int n, int k) {
    int nmax = k, l = 2 * k + 1, r = 2 * k + 2;
    if (l < n && comp(a + nmax * elemsize, a + l * elemsize)) nmax = l;
    if (r < n && comp(a + nmax * elemsize, a + r * elemsize)) nmax = r;
    if (nmax != k) {
        swap(a + k * elemsize, a + nmax * elemsize, elemsize);
        heap_down(a, n, nmax);
    }
}

// Heap sort function
void heap_sort(void * a, int n) {
    int k;
    for (k = n / 2 - 1; k >= 0; k--) heap_down(a, n, k);
    for (k = n - 1; k >= 0; k--) {
        swap(a + 0 * elemsize, a + k * elemsize, elemsize);
        heap_down(a, k, 0);
    }
}

// Sort method handler
void method_handler(int SORTMETHOD, void * a, int n, int elemsize) {
    switch (SORTMETHOD) {
    case BUBBLE: {
        bubble_sort(a, n);
        return;
    }
    break;
    case INSERT: {
        insert_sort(a, n);
        return;
    }
    break;
    case SELECTION: {
        selection_sort(a, n);
        return;
    }
    break;
    case COMB: {
        comb_sort(a, n);
        return;
    }
    break;
    case SHELL: {
        shell_sort(a, n);
        return;
    }
    break;
    case QUICK: {
        quick_sort(a, n);
        return;
    }
    break;
    case MERGE: {
        int b[n];
        merge_sort(a, n, b);
        return;
    }
    break;
    case HEAP: {
        heap_sort(a, n);
        return;
    }
    break;
    }
    exit(0);
}

// Main sort function
int sort(void * a, int n, int elemsize, int( * comp)(void * a1, void * a2)) {
    if (SORTMETHOD > 7 || SORTMETHOD < 0) {
        fprintf(stderr, "Sort method error\n");
        exit(1);
    }
    if (SORTDIRECTION > 1 || SORTDIRECTION < 0) {
        fprintf(stderr, "Sort direction error\n");
        exit(1);
    }
    if (comp == NULL) {
        fprintf(stderr, "Comparison function pointer error\n");
        exit(1);
    }
    method_handler(SORTMETHOD, a, n, elemsize);
    return 0;
}
