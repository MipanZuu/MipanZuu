//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//


#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
    unsigned long long a, b, c;
    cin >> a >> b;
    if (a == b) {
        cout << "Y" << endl;
    }
    else {
        if (a % 3 == 1 && b % 2 == 1) {
            cin >> c;
            if (c % 2 == 0) {
                cout << "G" << endl;
                return 0;
            }
            cout << "Y" << endl;
            return 0;
        }
        cout << "G" << endl;
    }
    return 0;
}



