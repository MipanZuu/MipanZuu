//
//  main.c
//  Hospital
//
//  Created by Denta Bramasta Hidayat on 09/09/21.
//

#include <stdio.h>

int main() {
    int vtbi, minutes, rate;
    printf("Volume to be infused (ml) => ");
    scanf("%d", &vtbi);
    printf("Minutes over which to infuse => ");
    scanf("%d", &minutes);
    
    rate = (60/minutes)*vtbi;
    printf("VTBI: %d ml\n", vtbi);
    printf("Rate: %d ml/hr\n", rate);
    return 0;
}
