//
//  main.c
//  Wartel
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <stdio.h>

int main() {
    int a, hasil = 0;
    while (scanf("%d", &a) != EOF) {
        hasil += a;
    }
    printf("%d", hasil);
    return 0;
}
