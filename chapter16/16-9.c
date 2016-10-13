// 16.8 Write an aligned malloc & free function that takes number of bytes and 
//      aligned byte (which is always a power of 2).

//      Example
//      align_malloc(1000, 128) will return a memory address that is a multiple
//      of 128 and that points to memory of size 1000 bytes.
//      align_free() will free memory allocated by align_malloc.

// Idea:
// 1. Use malloc routine of C to implement this.
//    Allocate memory of size (bytes required + alignment - 1 + sizeof(void *))
//    alignment: malloc can give us any address and we need to find a multiple 
//       of alignment.
//    (Therefore, at maximum multiple of alignment, we will be alignment - 1
//     bytes away from any location.)
//    sizeof(size_t): we are returning a modified memory pointer to user, which
//        is different from the one that would be returned by malloc. We also 
//        need extra space to store the address given by malloc, so that we can 
//        free it by calling free provided by C.
// 2. If it returns NULL, then aligned_malloc will fail and we return NULL.
// 3. Else, find the aligned memory address which is a multiple of alignment.
// 4. Store the address returned by malloc, which will be required by 
//    aligned_free.
// 5. Return the modified pointer.

// The code

#include <stdio.h>
#include <stdlib.h>

void * aligned_malloc(size_t required_bytes, size_t alignment)
{
	void* p1;
	void** p2;
	int offset = alignment - 1 + sizeof(void*);
	if((p1 = (void*) malloc(required_bytes + offset)) == NULL) 
		return NULL;

	p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));

	p2[-1] = p1;

	// What if the p1 returned is so close to alignment that p2[-1] is an 
	// illegal address to write to?
	// Or there is some kind of mechnism to ensure that this would never 
	// happen?

	return p2;
}

void aligned_free(void *p)
{
	free(((void**)p)[-1]);
}


int main()
{
	void * p = aligned_malloc(1000, 128);

	printf("%p\n", p);

	aligned_free(p);

	return 0;
}





