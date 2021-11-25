//
//  main.c
//  hydroelectric dam
//  
//  Created by Denta Bramasta Hidayat on 09/09/21.
//

#include <stdio.h>
#define gravity 9.80

int main() {
    float mass = 1000, height = 170, w;
    w = mass*gravity*height;
    printf("%.2f\n", w);
    return 0;
}
