//
//  main.cpp
//  Modifed Stack
//
//  Created by Denta Bramasta Hidayat on 14/05/21.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    stack<int>myStack;
    int a;
    string input;
    int count = 0;
    
    cin >> a;
    
    for(int b = 0; b < a; b++){
        cin >> input;
        if (input == "add") {
            int number, times;
            cin >> number >> times;
            for (int i = 0; i<times; i++) {
                myStack.push(number-count);
            }
            cout << myStack.size() << endl;
        }
        if (input == "del") {
            int number;
            cin >> number;
            cout << myStack.top()+count << endl;
            for (int j = 0; j < number; j++) {
                myStack.pop();
            }
        }
        if (input == "adx") {
            int denta;
            cin >> denta;
            count = count+denta;
//            cout << count << endl;
        }
        if (input == "dex") {
            int sera;
            cin >> sera;
            count = count-sera;
//            cout << count << endl;
    }
    
}
    
    return 0;
}
