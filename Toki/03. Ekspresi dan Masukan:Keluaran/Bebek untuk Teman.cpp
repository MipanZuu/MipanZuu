//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>
using namespace std;


int main() {
    int a, b, modu1, modu2;
    cin >> a >> b;
    
    modu1 = a % b;
    modu2 = a/b;
    
    cout << "masing-masing " << modu2 << endl;
    cout << "bersisa " << modu1 << endl;
 
    
    cin.get();
    return 0;
}
