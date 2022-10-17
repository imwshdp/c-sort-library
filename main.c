#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

int comp(void * a1, void * a2) {
    if (SORTDIRECTION == ASCENDING) {
        if ( * ((int * ) a1) < * ((int * ) a2)) return -1;
    }
    if (SORTDIRECTION == DESCENDING) {
        if ( * ((int * ) a1) > * ((int * ) a2)) return 1;
    }
    return 0;
}

// All Sorts Testing Function
int librarytest() {
    int i, j, z, n = 10;
    int a[n];
    elemsize = sizeof(int);
    for (i = 0; i < 8; i++) {
        for (z = 0; z < n; z++) {
            a[z] = rand() % 100;
        }
        printf("\nTesting Sort #%d", i + 1);
        SORTMETHOD = i;
        for (j = 0; j < 2; j++) {
            printf("\ndirection number %d: ", j + 1);
            SORTDIRECTION = j;
            sort(a, n, elemsize, * comp);
            for (z = 0; z < n; z++) {
                printf("%d ", a[z]);
            }
        }
        printf("\n\n");
    }
}

int main() {
    int i, n = 10;
    int a[n];
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    elemsize = sizeof(int);

    // Your custom value for sort details
    //SORTMETHOD=MERGE;
    //SORTDIRECTION=DESCENDING;

    printf("\n\n");
    sort(a, n, elemsize, * comp);
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    // Testing call
    //librarytest();

    return 0;
}
