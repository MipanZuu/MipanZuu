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
    string S, T;
    cin >> S >> T;
    while (S.find(T) < S.size()) {
        S.erase(S.find(T), T.size());
    }
    cout << S;
}
