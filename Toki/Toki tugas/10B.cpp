//
//  main.cpp
//  Toki 10 B
//
//  Created by Denta Bramasta Hidayat on 02/06/21.
//

#include <bits/stdc++.h>
using namespace std;
priority_queue<int>myPQ;

int main(int argc, const char * argv[]) {
    int N, number, input;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> number;
        
        if (number == 1) {
            cin >> input;
            myPQ.push(input);
        }
        else if (number == 2){
            cout << myPQ.top() << endl;
        }
        else if (number == 3){
            myPQ.pop();
        }
    }
}
