//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//


#include <bits/stdc++.h>
using namespace std;

long long dynamic[50001] = {0};
unsigned short N, Money[501];
bool food[50001] = {0};
 
long long swap(int x) {
    if(x == 0){
        return 0;
    }
 
    if(food[x - 1]){
        return dynamic[x - 1];
    }
 
    if(x < Money[0]){
        food[x - 1] = true;
        dynamic[x - 1] = INT_MAX;
    }
 
    long long minimum = INT_MAX;
    for(unsigned short i = 1; i <= N; i++){
        if(Money[i] <= x){
            long long val = swap(x - Money[i]) + 1;
            if(val < minimum) minimum = val;
        }
    }
    food[x - 1] = true;
    dynamic[x - 1] = minimum;
    return minimum;
}
 
int main() {

    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> Money[i];
    }
    unsigned short K;
    cin >> K;
    
    long long ans = swap(K);
    cout << ((ans >= INT_MAX) ? -1 : ans) << endl;
 
    return 0;
}

