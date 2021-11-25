#include<stdio.h>
#include<string.h>

void removingSpace(char *word){
    int count = 0;
    
    int i;
    for(i = 0; i < strlen(word); i++)
    if(word[i] != ' ')
    word[count++] = word[i];
    
    word[count] ='\0';
    
}

int main(){

  char tama[100];
  int a, b,length;
  
  do{
    scanf ("%[^\n]%*c",tama);
    removingSpace(tama);
    if(strcmp(tama, "exit")==0){
    break;
    
    }else {
    length =strlen(tama);
   
    for(a=1;a<length;a++){
        for(b=0;b<length-a;b++){
            if(tama[b]>tama[b+1]){
                char temp =tama[b];
                tama[b] = tama[b+1];
                tama[b+1]=temp;
                    }
                }
            }
    
        printf("%s\n",tama);
        }
   }
    while(strcmp(tama,"exit")!=0);
   
   return 0;
}
