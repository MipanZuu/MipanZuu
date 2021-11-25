//
//  main.c
//  Metro City
//
//  Created by Denta Bramasta Hidayat on 11/09/21.
//

/*
 konst
 new_litres_per_flush = 2,
 old_litres_per_flush = 15,
 cost_of_new_toilets = 150,
 toilets_per_person = 3,
 daily_number_of_flushes = 14
 
 input     = population
 
 output    = liters/day yg baru dan cost water ke saved  dengan toilet baru
 
 algorithm
 
 1. input populasi
 2. calculate kebutuhan toilet
 3. calculate cost install toilet
 4. calculate water yang di flushed di toilet lama
 5. calculate water yang di flushed di tolet baru
 6. calculate selisih dari water flushed lama - water flushed baru...estimate the magnitude
 7. output the magnitude and output cost install toilet
 
 */

#include <stdio.h>


int main(){
int new_litres_per_flush = 2, old_litres_per_flush = 15, cost_of_new_toilets = 150, toilets_per_person = 3, old_water_flushed_per_day, new_water_flushed_per_day, litres_of_water_saved_per_day, cost_of_water_saved, daily_number_of_flushes = 14;
int size_of_community;

 printf("Enter the population size> ");
   //   1. input populasi
 scanf("%d", &size_of_community);
   
 // 3. calculate cost install toilet
 cost_of_water_saved = size_of_community * cost_of_new_toilets;
 
 // 4. calculate water yang di flushed di toilet lama
 old_water_flushed_per_day = (((size_of_community / toilets_per_person) * daily_number_of_flushes) * old_litres_per_flush);
 
 // 5. calculate water yang di flushed di toilet baru
 new_water_flushed_per_day = (((size_of_community / toilets_per_person) * daily_number_of_flushes) * new_litres_per_flush);
 
 // 6. calculate selisih dari water flushed lama - water flushed baru...estimate the magnitude
 litres_of_water_saved_per_day = old_water_flushed_per_day - new_water_flushed_per_day;
 
 // 7. output the magnitude and output cost install toilet
 printf("With a community of %d people, installing newer efficient toilets will save %d litres per day at a cost of $%d dollars to install the new toilets.\n", size_of_community, litres_of_water_saved_per_day, cost_of_water_saved);
   
   return 0;
   
}


