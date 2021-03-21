//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>

using namespace std;


int main() {
    
    int a, hasil = 0;
    int b;
    
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        hasil += b;
    }
    cout << hasil << endl;
    
    cin.get();
    return 0;
}

