//
//  main.c
//  Dollars to Pounds
//
//  Created by Denta Bramasta Hidayat on 09/09/21.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float dollar, pounds;
    printf("Insert $");
    scanf("%f", &dollar);
    pounds = dollar*0.65;
    
    printf("%.2f GBP\n", pounds);
    return 0;
}
