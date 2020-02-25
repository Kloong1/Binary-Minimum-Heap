#include <stdio.h>
#define ElementType int
#define HEAP_CAPACITY 1024

typedef struct _HEAP{
	int capacity;
	int size;
	ElementType elements[HEAP_CAPACITY];
} HEAP;

int isEmpty(HEAP* h){
	return (h->size == 0);
}

int isFull(HEAP* h){
	return (h->size == h->capacity - 1);
}

void percolatingDown(HEAP* h, int index, int element){
	int i = 0, child = 0;

	/* percolating-Down needs child*/
	for(i = index ; i*2 <= h->size ; i = child ){

		child = i * 2;
		/* when child has sibling and sibling has smaller element*/
		if(child != h->size && h->elements[child] > h->elements[child + 1])
			child++;
		
		/* change element if child has smaller element */
		if(h->elements[child] < element)
			h->elements[i] = h->elements[child];

		/* child has bigger element -> don't need to do percolating-Down anymore */
		else
			break;
	}
		h->elements[i] = element;
}

void buildHeap(HEAP* h){
	int i = 0;
	/* do percolating-Down for every each non-leaf node. O(n) complexity */
	for(i = h->size / 2 ; i > 0 ; i-- )
		percolatingDown(h, i, h->elements[i]);
}

void printHeap(HEAP* h){
	int i = 0, j = 0;

	/* print heap with hierachy  */
	for(i = 1 ; i <= h->size ; i *= 2){
		for(j = i; j < i * 2 && j <= h->size ; j++){
			printf("%d ", h->elements[j]);
		}
		printf("\n");
	}
}

void insertHeap(HEAP* h, ElementType e){
	if(isFull(h)){
		printf("Heap is full!\n");
		return;
	}

	int i = 0;
	
	/* do percolating-Up */
	for(i = ++h->size ; i > 1 && h->elements[i/2] > e ; i /= 2)
			h->elements[i] = h->elements[i/2]; 

	h->elements[i] = e;
	
}

ElementType deleteMin(HEAP* h){
	if(isEmpty(h)){
		printf("\nHeap is empty!\n");
		return -1;
	}

	int min = h->elements[1];
	int lastElement = h->elements[(h->size)--];

	percolatingDown(h, 1, lastElement);

	return min;
}
