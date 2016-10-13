// 16.10 Write a function called my2DAlloc which allocates a two dimensional 
//       array. Minimize the number of calls to malloc and make sure that the 
//       memory is accessible by the notation arr[i][j].

// Idea:
// 1. Allocate one block of memory to hold the row vector and the array data.

// The code

#include <stdlib.h>
#include <stdio.h>


int ** my2DAlloc(int rows, int cols)
{
	int header = rows * sizeof(int*);
	int data = rows * cols * sizeof(int);
	int** rowptr = (int**)malloc(header + data);

	int* buf = (int*)(rowptr + rows);

	int k;
	for(k = 0; k < rows; ++k)
		rowptr[k] = buf + k * cols;

	return rowptr;
}

int main()
{
	int** a = my2DAlloc(10, 10);
	free(a);

	return 0;
}