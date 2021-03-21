//
//  main.cpp
//  TUGAS STRUKDAT
//
//  Created by Denta Bramasta Hidayat on 20/03/21.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    while (1)
        {
        int a, arr[1001];
        
        cin >> a;
        if (a==0) {
         return 0;
     }
        for (int n = 1; n <= a; n++) {
            cin >> arr[n];
        }
        
        
        stack<int>car;
        int counter = 1;   //counter for check the car
        bool tr = true;    //true = 1 or false = 0
          
        
        for (int n = 1; n <= a; n++) {
            if (arr[n] == counter) {
                counter++;
                } //if array is equal to counter so counter increment
            else {
                while (!car.empty() && car.top() == counter) {
                        car.pop();
                        counter++;
                    } //car top is equal to counter so car pop
                while (!car.empty() && car.top() < arr[n]) {
                        tr = false;
                        break;
                }// car top is not equal to the real track (arr[n]) so "false" then break to the output
                car.push(arr[n]);
            } // end of else and push the arr[n]
            
        }

        if (tr) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
         
     }
}
