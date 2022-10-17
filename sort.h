#if!defined(_SORT_H_)
#define _SORT_H_
#define BUBBLE 0
#define INSERT 1
#define SELECTION 2
#define COMB 3
#define SHELL 4
#define QUICK 5
#define MERGE 6
#define HEAP 7
#define ASCENDING 0
#define DESCENDING 1
extern int elemsize;
extern int SORTMETHOD;
extern int SORTDIRECTION;

void swap(void * a1, void * a2, int elemsize);
void bubble_sort(void * a, int n);
void insert_sort(void * a, int n);
void selection_sort(void * a, int n);
void comb_sort(void * a, int n);
void shell_sort(void * a, int n);
void partition(void * a, int l, int r);
void quick_sort(void * a, int n);
void merge(void * a, int n, void * b);
void merge_sort(void * a, int n, void * b);
void heap_down(void * a, int n, int k);
void heap_sort(void * a, int n);
void method_handler(int SORTMETHOD, void * a, int n, int elemsize);
int sort(void * a, int n, int elemsize, int( * comp)(void * a1, void * a2));
#endif