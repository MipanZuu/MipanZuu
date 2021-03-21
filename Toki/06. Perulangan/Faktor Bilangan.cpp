//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>

using namespace std;


int main() {
    
    int a;
    cin >> a;
    for (int i = a; i > 0; i--) {
        if (a % i == 0) {
            cout << i << endl;
        }
    }
    
    
    cin.get();
    return 0;
}
