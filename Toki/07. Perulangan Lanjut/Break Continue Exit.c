//
//  main.c
//  test test
//
//  Created by Denta Bramasta Hidayat on 09/03/21.
//

#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    
    for (int i = 1; i <= a; i++) {
        if (i % 10 == 0) {
            printf("");
        }
        else if (i == 42) {
            printf("ERROR");
        break;
        } else
            printf("%d\n", i);
    }
    
    return 0;
}
