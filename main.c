#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void insert(HEAP* h);
int printMenu();

int main()
{
	FILE* fp = fopen("data.txt", "r");

	HEAP* h = (HEAP*)malloc(sizeof(HEAP));
	h->capacity = HEAP_CAPACITY;
	h->size = 0;

	int element = 0;
	int i = 1;
	while(fscanf(fp, "%d", &element) != EOF){
		h->elements[i++] = element; // index starts from 1
		h->size++;
	}

	buildHeap(h);

	int input = 0;
	int min = 0;
	int exit = 0;

	while(!exit){
		input = printMenu();

		switch (input) {
			case 1:
				insert(h);
				break;
			case 2:
				min = deleteMin(h);
				printf("Min: %d\n", min);
				break;
			case 3:
				printHeap(h);
				break;
			case 4:
				exit = 1;
		}
		fflush(stdin);
		printf("\n");
	}

	free(h);
	fclose(fp);
	return 0;
}

int printMenu(){
	printf("\n1. Insert\n");
	printf("2. Delete Min\n");
	printf("3. Print Heap\n");
	printf("4. Exit\n");
	
	int input = 0;
	printf("Input: ");
	scanf("%d", &input);

	return input;
}

void insert(HEAP* h){
	fflush(stdin);

	int input = 0;
	printf("\n\nInsert\n");
	printf("Input: ");
	scanf("%d",&input);

	insertHeap(h, input);
}
