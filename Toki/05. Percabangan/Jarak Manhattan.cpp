//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>
#include <stdlib.h>
using namespace std;


int main() {
    
    int hasil1, hasil2, x1, x2, y1, y2, manhattan;
    cin >> x1 >> y1 >> x2 >> y2;
    
    hasil1 = x1 - x2;
    hasil2 = y1 - y2;
    
    manhattan = abs(hasil1) + abs(hasil2);
    cout << manhattan << endl;
    
    cin.get();
    return 0;
}
