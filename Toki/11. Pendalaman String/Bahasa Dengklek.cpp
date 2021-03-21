//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>
#include <string>
using namespace std;

int main (){
    string S, A;
    cin >> S;
    
    A = S.length();
    for (int i = 0; i < S.length(); i++) {
        if (S[i] >= 97 || S[i] < 65) {
            S[i] = S[i] - 32;
        }else {
            S[i] = S[i] + 32;
        }
        cout << S[i];
    }
}
