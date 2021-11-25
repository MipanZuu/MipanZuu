// Created by Denta Bramasta (5025201116)

#include <stdio.h>

// Print Array 
void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// swap
void swap(int *xp, int *yp) {
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

// bubble sort algorithm
void bubbleSort(int arr[], int n) {
   int i, j, swapped;        // optimized with bool `swapped`:
   for (i = 0; i < n-1; i++) {
      swapped = 0;
      for (j = 0; j < n-i-1; j++) {
        //   printf("%d ", arr[j]);
         if (arr[j] > arr[j+1]) {
            printf("arr j = \t %d \n", arr[j]);
            printf("arr j+1 = \t %d \n", arr[j+1]);
            swap(&arr[j], &arr[j+1]);
            printArray(arr, n);
            swapped = 1;
         }
      }
      if (swapped == 0)
         break;
   }
}

//insertion sort Algorithm
void insertionSort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
      key = arr[i];
      j = i-1;
    
      while (j >= 0 && arr[j] > key) {
         arr[j+1] = arr[j];
         j = j-1;
      }
      arr[j+1] = key;
   }
}

// merge
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Mergesort
void mergeSort(int *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}

// partition is a part of quicksort
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  // selecting last element as pivot
    int i = (low - 1);  // index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort
void quicksort(int a[], int p, int r)    
{
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// HeapSort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}  

// selectionsort       
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // Original array: 
    // 5 2 6 7 2 1 0 3

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i; // min_idx = 0 = 5
        
        for (j = i+1; j < n; j++)

          if (arr[j] < arr[min_idx])
          // arr[j] = 1 = 2
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);

        // sorting = 2 5 
    }
}  


int main () {
    // int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int arr[] = {7, 2, 8, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array:\n");
    printArray(arr, n);
    

    //Bubblesort
    bubbleSort(arr, n);
    printf("Sorted array with Bubblesort: \n");
    printArray(arr, n);

    //InsertionSort
    // insertionSort(arr, n);
    // printf("Sorted array with InsertionSort: \n");
    // printArray(arr, n);

    //MergeSort
    // mergeSort(arr, 0, n-1);
    // printf("Sorted array with Mergesort: \n");
    // printArray(arr, n);

    // quicksort
    // quicksort(arr, 0, n-1);
    // printf("Sorted array with quick sort: \n");
    // printArray(arr, n);

    // SelectionSort
    // selectionSort(arr, n);
    // printf("Sorted array with Selectionsort: \n");
    // printArray(arr, n);

    // HeapSort
    // heapSort(arr, n);
    // printf("Sorted array with Heapsort: \n");
    // printArray(arr, n);
}