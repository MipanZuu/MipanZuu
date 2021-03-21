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
    
    if (a == 0){
        cout << "nol" << endl;
    }else if (a > 0){
            cout << "positif" << endl;
    }else if (a < 0){
        cout << "negatif" << endl;
    }
    
    
    cin.get();
    return 0;
}
