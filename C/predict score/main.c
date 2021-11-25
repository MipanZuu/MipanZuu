//
//  main.c
//  predict score
//
//  Created by Denta Bramasta Hidayat on 09/09/21.
//

#include <stdio.h>

int main ()
{
  char desiredgrade;
  double min_average, currentaverage, weight, score;
    printf("Enter desired grade> ");
    scanf("%c", &desiredgrade);
    printf("Enter minimum average required> ");
    scanf("%lf", &min_average);
    printf("Enter current average in course> ");
    scanf("%lf", &currentaverage);
    printf("Enter how much the final counts\nas a percentage of the course grade> ");
    scanf("%lf", &weight);
    
    score=((min_average-((100-weight)* (currentaverage/100)))) *(100/weight);
  
    printf("\n");
  printf("You need a score of %.2f on the final to get %c\n",score, desiredgrade);
  
  return 0;
}
