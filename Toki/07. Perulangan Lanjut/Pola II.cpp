//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>

using namespace std;


int main() {
    
    int a, j, i;
  
    cin >> a;
    for (i = 1; i <= a; i++) {
        for (j = 0; j < a-i; j++) {
            cout << " ";
        }
        for (j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    
    
    
    cin.get();
    return 0;
}
