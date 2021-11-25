#include <stdio.h>

int main() {
  
    int M,N,T; // M for cars in front of ours ; N for cars behind us ; T for time in seconds
    int mob1, mob2, sum , totmob , T2;
    
    scanf("%d %d %d",&M,&N,&T);
    
    mob1 = T / 85 * 12; // 12 itu mobil yang bsia lewat dalam 60 detik
    T2=0;
    mob2=0;
    if (T % 85 > 25 ){
        T2 =( T % 85 )-25;
        mob2 = T2/5;
    }
    totmob = mob1 + mob2;
    sum = M + N + 1;
    if(totmob > M){
        printf("YES!");
    }
    else{
        printf("NO!");
    }
 
    if(sum > totmob){
            printf(" %d\n", sum-totmob);
    }
    else{
        printf(" 0\n");
    }
    
    return 0;
}