//
//  main.c
//  Matrix
//
//  Created by Denta Bramasta Hidayat on 06/10/21.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int tcase, i, j, k, rows, colums;
    int matrix[101][101];
    
    scanf("%d", &tcase);
    
    for (i = 0; i < tcase; i++)
    {
        scanf("%d %d", &rows, &colums);
        for(j = 0; j < rows; j++)
        {
            for(k = 0; k < colums; k++)
            {
                scanf ("%d", &matrix[j][k]);
            }
        }
        
    // MARK: Section 2
        for(k = 0; k < colums; k++)
        {
            for(j = 0; j < rows; j++)
            {
                printf("%d", matrix[j][k]);
            }
        }
    }
}
