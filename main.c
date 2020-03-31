#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.c"
#include "utils.c"

#define SIZE 10000

int main() {
	int elements[SIZE];

	printf("That's a sort analysis using a array of elements with size: %d\n\n", SIZE);

	createElements(elements, SIZE);

	sortAnalytics(elements, "Bubble Sort", bubbleSort, SIZE);
	sortAnalytics(elements, "Selection Sort", selectionSort, SIZE);
	sortAnalytics(elements, "Insertion Sort", insertionSort, SIZE);
	sortAnalytics(elements, "Quick Sort", quickSort, SIZE);
}