#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main () {
    
    int angka[21]={0};
    char string[21][101];
    
    int C, N;
    
    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        scanf("%d %s", &angka[i], string[i]);
    }
    scanf("%d", &N);
    
    for (int j = 1; j <= N; j++) {
        int flag = 0 ;
        for (int i = 0 ; i < C; i++) {
            if (j % angka[i] == 0) {
                printf("%s\n", string[i]);
                flag = 1 ;
            }
        }
        if (!flag)
            printf("%d\n", j);
    }

    return 0;
}

