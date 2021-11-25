#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibo(int n);
void encryput(char c[],int d,char e[]);
void decrypt(char c[],int d,char e[]);

int fibonacci(int n){
     if (n <= 1)
      return n;
   return fibonacci(n-1) + fibonacci(n-2);
}

void encryput(char c[],int d,char e[]){
    int kiwa,result;
    int i;
    int x;
    
     for(i = 0; c[i] != '\0';i++){
        kiwa = c[i];
        
        if(kiwa >= 'a' && kiwa <= 'z'){
            
            x = kiwa;
                        
            result = (x+(d%26)-97)%26 +97;
            
            c[i] = result;
        }
     
           else if(kiwa >= 'A' && kiwa <= 'Z'){
               
            result = (kiwa+(d%26)-65) % 26 +65;
            c[i] = result;
            }
        }
        strcat(e,c);
    }
    
void decrypt(char c[],int d,char e[]){
    int kiwa,result;
    int i;
    int x;
    
     for(i = 0; c[i] != '\0';i++){
        kiwa = c[i];
        
        if(kiwa >= 'a' && kiwa <= 'z'){
            
            x = kiwa;
                        
            result = (x+(26-d%26)-97)%26 + 97;
            
            c[i] = result;
        }
     
           else if(kiwa >= 'A' && kiwa <= 'Z'){
               
            result = (kiwa+(26-d%26)-65) % 26 + 65;
            c[i] = result;
            }
        }
        strcat(e,c);
    }

    

int main(){
     
    int k,s,again;
    char M[1000];
    int fibo;
    scanf("%d",&k);
    
    
    int j;
    char cat[16000]="";
    
    
    for ( j = 0 ; j < k ;j++){
    scanf("%d",&again);
    if(again == 0 ||again == 1){
    scanf("\n%d\n",&s);
    fibo = fibonacci(s);
    fgets(M,1000,stdin);
    
    switch(again){
        
    case 0 :
        encryput(M,fibo,cat);
        break;
    
    case 1 :
        decrypt(M,fibo,cat);
        break;
        }
    }
    
    else{
    printf("Mode is not valid!");
    }
}
printf("%s",cat);
    return 0;
}
