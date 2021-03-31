//
//  main.c
//  RightSmallerThan
//
//  Created by Denta Bramasta Hidayat on 01/04/21.
//

#include <stdio.h>
#include <stdlib.h>

void ArrayLeftLow (int arr[], int *Smaller, int n)
{
int i, j;

for (i = 0; i < n; i++)
    Smaller[i] = 0;

for (i = 0; i < n; i++)
{
    for (j = i; j < n; j++)
    {
    if (arr[j] < arr[i])
        Smaller[i]++;
    }
}
}

/* Utility function that prints out an array on a line */
void printArray(int arr[], int size)
{
int i;
    printf("[ ");
for (i=0; i < size; i++)
    printf("%d ", arr[i]);
    printf("]");
    printf("\n");
}

int main()
{
int arr[] = {8, 5, 11, -1, 3, 4, 2};
//int ray[] = {};
//int gus[] = {1};
int den[] = {0, 1, 1, 2, 3, 5, 8, 13};
int ser[] = {13, 8, 5, 3, 2, 1, 1, 0};
int bay[] = {8, 5, 2, 9, 5, 6, 3};
    
int n = sizeof(arr)/sizeof(arr[0]);
int *low = (int *)malloc(sizeof(int)*n);
    
ArrayLeftLow(arr, low, n);
printArray(low, n);
    
/*ArrayLeftLow(ray, low, n);
printArray(low, n);
    
ArrayLeftLow(gus, low, n);
printArray(low, n);*/
    
ArrayLeftLow(den, low, n);
printArray(low, n);

ArrayLeftLow(ser, low, n);
printArray(low, n);
    
ArrayLeftLow(bay, low, n);
printArray(low, n);
return 0;
}
