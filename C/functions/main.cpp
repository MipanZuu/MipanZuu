#include <stdio.h>

void print (int sdf, int rip);
int main(){
    int a;
    int i;
    scanf("%d", &a);
    int num[a];
    for (i=0; i<a; i++) {
        scanf("%d", &num[i]);}
    print(a, num[i]);
    return 0;
}

void print (int sdf, int rip){
    int i;
    
for (i=0; i<sdf; i++) {
    if (i>=0) {
        printf("LEAVE\n");
    }
    else{
        printf("ERASE\n");
    }
}
}
