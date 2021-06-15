//
//  main.c
//  FINAL
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//

#include <stdio.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    unsigned long long a, i, j;
    unsigned long long arr[1000000];
    bool apa = false;
    
    scanf(%lld) a;
    for (i = 0; i < a; i++) {
        cin >> arr[i];
    }
    for (i = 0; i < a; i++) {
        for (j = i+1; j < a; j++) {
            if (arr[i] == arr[j])
                apa = true;
            
    }
}
        if (apa == true) {
            cout << "G" << endl;
        }
    else {
        cout << "Y" << endl;
    }
    return 0;
}


