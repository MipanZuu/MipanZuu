//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>

using namespace std;


int main() {
    
    int num = 0, a, j, i;
  
    cin >> a;
    for (i = 1; i <= a; i++) {
        for (j = 0; j < i; j++) {
            cout << num;
            num++;
            if (num > 9) {
                num = 0;
            }
        }
        cout << endl;
    }
       
    
    
    cin.get();
    return 0;
}
