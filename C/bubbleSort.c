#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

void bubblesort(int *array, const int size);

int main(){
    int a[SIZE]={7, 32, 54, 11, 1, 45, 7, 88, 45};
    int i; //Counter
    
    for (i=0; i<SIZE; i++) {
        printf("%4d", a[i]);
    }
    bubblesort(a, SIZE);
    printf("The sorted elements in ascending order");
    for (i=0; i<SIZE; i++) {
        printf("%4d", a[i]);
    }
    printf("\n");
    return 0;
}


