//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    
    double a, t, modu1;
    cin >> a >> t;
    
    modu1 = 0.5 * a * t;
    cout << fixed << setprecision (2) << modu1 << endl;
    
 
    
    cin.get();
    return 0;
}
