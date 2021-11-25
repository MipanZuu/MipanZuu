//
//  main.c
//  Rectangular yard
//
//  Created by Denta Bramasta Hidayat on 11/09/21.
//

#include <stdio.h>
#define two_square_feet_a_second  2
int main(int argc, const char * argv[]) {
    int length_of_yard,
    width_of_yard,
    length_of_house,
    width_of_house,
    area_of_yard,
    area_of_house,
    time;

    printf("input length of yard> ");
    scanf("%d", &length_of_yard);
    printf("input width of yard> ");
    scanf("%d", &width_of_yard);
    printf("input length of house> ");
    scanf("%d", &length_of_house);
    printf("input width of house> ");
    scanf("%d", &width_of_house);
    
    area_of_yard = length_of_yard * width_of_yard;
    area_of_house = length_of_house * width_of_house;
    
    time = area_of_yard/two_square_feet_a_second;
    
    printf("Area of the house is %d\n", area_of_house);
    printf("And to cut the grass at %d square feet on the yard, it will take %d seconds\n", area_of_yard, time);
    return 0;
}
