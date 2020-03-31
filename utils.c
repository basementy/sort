#include <stdlib.h>
#include <time.h>

void createElements(int elements[], int size) {
  int i;
  srand(time(NULL));
  
  for( i = 0; i < size; i++) {
    elements[i] = rand() % size;
  }
}

void sortAnalytics(int elements[], char sortType[], int * (*f)(int*, int), int size) {
	double time_spent;
	clock_t begin,end;
	size_t temp_size = sizeof(*(elements)) * (size);

	int * copy = malloc(temp_size);
	memcpy(copy, elements, temp_size);

	begin = clock();

	(*f)(copy, size);

	end = clock();

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%s, %fs \n", sortType, time_spent);

	free(copy);
}