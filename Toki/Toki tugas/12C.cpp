//
//  main.cpp
//  12 C
//
//  Created by Denta Bramasta Hidayat on 03/06/21.
//

#include <bits/stdc++.h>
using namespace std;
int N;
double x, y, mn, sama;
bool check;
pair<double, double> arr[1000005];

double luas_segitiga(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    return fabs((a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second)))/(double)2;
} //formula area of triangle


int main(int argc, const char * argv[]) {
    check = 0;
    mn = 1e9;  //10 to the power by ^9
    sama = 1e9;
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }
    
    for(int i = 1; i <= N-2; i++) {
        for(int j = i + 1; j <= N-1; j++) {
            for(int k = j + 1; k <= N; k++) {
                
        double luas = luas_segitiga(arr[i], arr[j], arr[k]);
                
        if(luas != 0) {
            check = 1;
            if(luas == mn) sama = min(sama, luas);
            mn = min(mn, luas);
            }
        }
    }
}
    if(check) {
        if (sama == mn)
            cout << "-1.00" << endl;
    else
        cout << fixed << setprecision(2) << mn << endl;
    }
    else
        cout << "-1.00" << endl;
}
