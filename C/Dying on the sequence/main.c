//
//  main.c
//  Dying on the sequence
//
//  Created by Denta Bramasta Hidayat on 06/10/21.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n, B;
    int curr = 0, next = 1, result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &B);
        curr = 0; next = 1; result = 0;
        printf("Sequence: %d,%d,", curr, next);
        result = curr + next;
        
    while (result <= B) {
        printf("%d,", result);
        curr = next;
        next = result;
        result = curr + next;
    }
        printf("\n");
    }
}
