#include <stdio.h>

int main(){
  double BTU_PER_GALLON, gallons, barrels, efficiency;

    BTU_PER_GALLON = 5800000;

    printf("Enter the efficiency of your house's oil furnace as a percentage> \n");
    scanf("%lf", &efficiency);
  
    printf("Enter the number of gallons of oil burned> \n");
    scanf("%lf", &gallons);
  
    barrels = BTU_PER_GALLON / 42;
  
  
}
