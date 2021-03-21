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
    int i, j;
    cin >> a >> j;
    
    for (i = 1; i <= a; i++) {
        if (i % j == 0) {
            cout << "* ";
            
        }else if (i % j != 0){
            cout << i << " ";
        }
    }
    
    
    
    cin.get();
    return 0;
}
