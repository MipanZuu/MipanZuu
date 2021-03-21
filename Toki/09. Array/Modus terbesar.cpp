//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>
using namespace std;

int main() {
    int n, arr[2000]={0}, max=0, ans = 0, l;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> l;
        arr[l]++;
    }
    for (int j=1; j<=1000; j++) {
        if (arr[j]>=max) {
            max = arr[j];
            ans = j;
        }
    }
    cout << ans << endl;
    return 0;
}
