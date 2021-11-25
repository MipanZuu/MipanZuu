//
//  main.c
//  Temperature
//
//  Created by Denta Bramasta Hidayat on 09/09/21.
//

#include <stdio.h>
#include <math.h>
int main() {
    float hours, minutes, t, T; // indentify the variables
    printf("Enter the hours ");
    scanf("%f", &hours); // input hours
    printf("Enter the minutes ");
    scanf("%f", &minutes); // input minutes
    
    t = hours + (minutes*1/60)+(1/3600); // convert to decimal
    
    printf("%.1f Hours\n", t); // print out the decimal time for check wether it's right or wrong
    
    T = (4*pow(t, 2)/t+2)-20;
    
    printf("Temperature (T) is %.2f \n", T);
    return 0;
}
