//
//  main.c
//  Week3
//
//  Created by Denta Bramasta Hidayat on 15/09/21.
//

/*
 CONSTANT
 
 ALGORITHM
 
 INPUT
 
 OUTPUT
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int d;
    int i, j;
    int sn;
    char m[100];
    
    scanf("%d", &d);
    char love, result;
    
    for (j=0; j<d; j++) {
        scanf("\n%d\n", &sn);
        fgets(m, 100, stdin);
        
        for (i=0; m[i] !='\0'; i++) {
            love=m[i];
            if (love >= 'a' && love <= 'z') {
                result=(love+sn-97)%26+97;
                m[i]=result;
            }
            else if (love >= 'A' && love <= 'Z'){
                result=(love+sn-65)%26+65;
                m[i]=result;
            }
        }
        printf("%s\n", m);
//        strcat(tam, m);
    }
    return 0;
}
