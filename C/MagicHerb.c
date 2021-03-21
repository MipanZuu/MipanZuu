//
//  01_magic_herb.c
//  01_magic_herb
//
//  Created by Denta Bramasta Hidayat on 25/11/20.
//


# include<stdio.h>
# define num 15

void number(int arr[], int a){
    if(a == 1){//recursive
        return;}
    
    int herb;
    herb = arr[a-2];
    
    int formula1 = herb + arr[a-1];//for formula 1
    int formula2 = herb - arr[a-1];//for formula 2
    int formula3 = (herb * 2) - arr[a-1];//for formula 3
    int formula4 = ((herb - 3) * 2) + arr[a-1];//for formula 4
    
    
    if(formula1 >= 65 && formula1 <=124){
        arr[a-2] = formula1;}
    
    if(formula2 >= 65 && formula2 <=124){
        arr[a-2] = formula2;}
    
    if(formula3 >= 65 && formula3 <=124){
        arr[a-2] = formula3;}
    
    if(formula4 >= 65 && formula4 <=124){
        arr[a-2] = formula4;}
    
        number(arr, a-1);
    printf("%c\n",arr[a-2]);//print output
}

int main(){
    int arr[num] = {94, 222, 221, 186, 181, 208, 207, 110, 187, 185, 17, 212, 115, 215, 100};
    int sum = 15;
        number(arr, sum);
    
    return 0;
}
