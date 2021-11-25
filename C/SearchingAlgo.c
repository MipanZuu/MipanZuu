#include <stdio.h>

// LinearSearch
int linearSearch(int arr[], int n, int item) {
   int i;
   for(i = 0; i < n; ++i) {
      if(item == arr[i])
        return i;
   }
   return -1;
}

// BinarySearch
int binarySearch(int arr[], int l, int r, int x)
// x == item to be search
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main () {
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int search = 12;
    
    // binarySearch
    // int result_b = binarySearch(arr, 0, n-1, search);
    // printf("BINARY SEARCH\n");
    // (result_b == -1) ? printf("The value that you are loooking for doesn't exist\n")
    //                  : printf("The value at index: %d\n", result_b);

    // LinearSearch
    int result_l = linearSearch(arr, n, search);
    printf("LINEAR SEARCH\n");
    (result_l == -1) ? printf("The value that you are loooking for doesn't exist\n")
                     : printf("The value at index: %d\n", result_l);
    
}