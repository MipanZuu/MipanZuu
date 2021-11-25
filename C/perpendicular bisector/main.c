//
//  main.c
//  perpendicular bisector
//
//  Created by Denta Bramasta Hidayat on 11/09/21.
//

#include <stdio.h>
int main() {
    double x1, x2, y1, y2, Xavg, Yavg, slope, slopemin, b;
    printf("Input coordinate x1 and y1\n");
    scanf("%lf %lf", &x1, &y1);
    printf("Input coordinate x2 and y2\n");
    scanf("%lf %lf", &x2, &y2);
    
    // compute the coordinates of the midpoint of the line segment between the two points by averaging the two x-coordinates and the two y-coordinates;
    Xavg = (x1+x2)/2;
    Yavg = (y1+y2)/2;
    
    slope = (y2-y1)/(x2-x1);
    slopemin = -1/(slope);
    b = Yavg - (slope * Xavg);
    
    printf("The initial coordinates were %.2lf, %.2lf and %.2lf, %.2lf.\nAnd the perpendicularis y = %.2lf + %.2lf\n", x1, x2, y1, y2, slopemin, b);
    return 0;
}
