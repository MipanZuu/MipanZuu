#include <stdio.h>
#include <string.h>
 
void printReverse(char str[]) {
    long length, c;
       char *begin, *end, temp;
     
       length = strlen(str);
       begin  = str;
       end    = str;
     
       for (c = 0; c < length - 1; c++)
          end++;
     
       for (c = 0; c < length/2; c++)
       {
          temp   = *end;
          *end   = *begin;
          *begin = temp;
     
          begin++;
          end--;
         
       }
    
    
    }

int isExit(char str[]) {
    if(str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't' && str[4] == '\0')
        return 1;
    return 0;
}

 
int main() {
    char str[128];
    while(1) {
        scanf("%s", str);
        if(isExit(str))
            break;
        printReverse(str);
        printf("%s", str);
        printf("\n");
    }
    return 0;
}

