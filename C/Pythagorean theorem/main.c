//
//  main.c
//  Pythagorean theorem
//
//  Created by Denta Bramasta Hidayat on 11/09/21.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int m, n, side1, side2, hypotenuse;
    printf("enter first integer number ");
    scanf("%d", &m);
    printf("enter second integer number ");
    scanf("%d", &n);
    side1 = pow(m, 2)-pow(n, 2);
    side2 = 2 * m * n;
    hypotenuse = pow(m, 2) + pow(n, 2);
    
    printf("side 1 = %d \n", side1);
    printf("side 2 = %d \n", side2);
    printf("hypotenuse = %d \n", hypotenuse);
    
    return 0;
}
