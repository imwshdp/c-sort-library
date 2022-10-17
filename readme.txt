NAME
	Sort Library
SYNOPSIS
	#include <sorts.h>
	int sort(void*array, int size, int elemsize, int(*comp)(void*a1,void*a2));
DESCRIPTION
	Function sort sorts an array with [size] elements of [elemsize] size. The base argument points to
	sortable array. The contents of the array are sorted in ascending or descending order according to
	default or custome value of parameter SORTDIRECTION. Sort method is determined by parameter SORTMETHOD.
	The elements are compared in function COMP, which return
	-1, if a1 < a2,
	0, if a1==a2,
	1, if a1>a2.
	The sort function must return sorted array of previously defined type.