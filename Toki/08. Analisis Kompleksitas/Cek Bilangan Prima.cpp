//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>
#include <cmath>
using namespace std;


int main() {
    
    int N;
  
    cin >> N;
    for (int i =  0; i < N; i++) {
        int x;
        cin >> x;

        bool prime = true;
    if (x==1) {
        prime = false;
        }
        
        for (int j = 2; j <= sqrt(x); j++) {
            if (x%j == 0) {
                prime = false;
            }
        }
        if (prime) {
            cout << "YA" << endl;
        }else {
            cout << "BUKAN" << endl;
        }
    }
    return 0;
}
