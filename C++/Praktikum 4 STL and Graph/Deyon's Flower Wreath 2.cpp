//
//  main.cpp
//  Praktikum modul 4 Graf
//
//  Created by Denta Bramasta Hidayat on 24/05/21.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find(int x, vector<int> &r) {
    if (r[x] != x)
        r[x] = find(r[x], r);
    return r[x];
}

int main() {

    int n, x, y;
    int min = INT_MAX, max = INT_MIN;

    cin >> n;

    vector<int> a ((2*n+1)), count ((2*n+1));

    for (int i = 1; i <= 2*n; i++) {
        a[i] = i;
        count[i] = 1;
    }

    for (int i = 0; i < n; i++) {

        cin >> x >> y;

        x = find(x, a); // x = parent of x
        y = find(y, a); // y = parent of y

        if (x != y) {
            a[x] = y;
            count[y] += count[x];
            count[x] = 0;
        }
    }
    
    for (int i = 1; i <= 2*n; i++) {
        if (count[i] > max)
            max = count[i];
        if (count[i] > 1 && count[i] < min)
            min = count[i];
    }

    cout << min << " " << max;

    return 0;
}

