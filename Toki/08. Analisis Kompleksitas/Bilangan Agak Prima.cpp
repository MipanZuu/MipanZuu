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
        int counter = 0;
        cin >> x;

        bool prime = true;
        
        for (int j = 2; j <= sqrt(x); j++) {
            if (x%j == 0) {
                counter ++;
                prime = false;
            }
        }
        if (counter >= 2) {
            cout << "BUKAN" << endl;
        }else {
            cout << "YA" << endl;
        }
    }
    return 0;
}
