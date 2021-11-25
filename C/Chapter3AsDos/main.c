//
//  main.c
//  TAXI FARE CALCULATOR
//
//  Created by Denta Bramasta Hidayat on 09/09/21.
//

#include <stdio.h>
#define mile_Cost 1.50

int main() {
    float beginning, ending, distance, fare;
    printf("TAXI FARE CALCULATOR\n\nEnter beginning odometer reading => ");
    scanf("%f", &beginning); // input for beginnning odometer
    printf("Enter ending odometer reading => ");
    scanf("%f", &ending); // input for ending odometer
    
    distance = ending - beginning; // distance of taxi
    fare = distance * mile_Cost; // fare of taxi
    
    printf("You traveled a distance of %.1f miles. At $%.2f per mile,\nyour fare is $%.2f\n", distance, mile_Cost, fare);
    
    return 0;
}
