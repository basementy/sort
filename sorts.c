void swapIndex(int *xp, int *yp)  {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

int * bubbleSort(int elements[], int size)  {
  int i, j;
  int n = size;

  for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)
      if (elements[j] > elements[j+1])
        swapIndex(&elements[j], &elements[j+1]);

	return elements;
}

int * insertionSort(int elements[], int size) {
  int i, key, j, n;
  n = size;

  for (i = 1; i < n; i++) {
    key = elements[i];
    j = i - 1;

    while (j >= 0 && elements[j] > key) {
        elements[j + 1] = elements[j];
        j = j - 1;
    }

    elements[j + 1] = key;
  }

  return elements;
}

int * selectionSort(int elements[], int size) {
  int i, j, min_idx;
  int n;

  n = size;

  for (i = 0; i < n-1; i++)  {
    min_idx = i;

    for (j = i+1; j < n; j++)
      if (elements[j] < elements[min_idx])
        min_idx = j;

    swapIndex(&elements[min_idx], &elements[i]);
  }

  return elements;
}

void quickSortSub(int elements[], int start, int end){
  int pivot, aux, i, j, mid;

  i = start;
  j = end;

  mid = (int) ((i + j) / 2);
  pivot = elements[mid];

  do{
    while (elements[i] < pivot) i = i + 1;
    while (elements[j] > pivot) j = j - 1;

    if(i <= j){
      aux = elements[i];
      elements[i] = elements[j];
      elements[j] = aux;
      i = i + 1;
      j = j - 1;
    }
  } while (j > i);

  if (start < j) quickSortSub(elements, start, j);
  if (i < end) quickSortSub(elements, i, end);
}

int * quickSort(int elements[], int size) {
  quickSortSub(elements, 0, size - 1);
  return elements;
}