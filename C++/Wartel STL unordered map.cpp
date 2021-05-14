//
//  main.cpp
//  Wartel STL
//
//  Created by Denta Bramasta Hidayat on 05/05/21.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    unordered_map<string, string>wartel;
    bool check = false;
    int N, Q;
    int i, j, k;
    char orang[50], telpon[10], searchh[10];
    
    cin >> N >> Q;
    
    for (i = 0; i < N; i++) {
        cin >> orang >> telpon;
    for (j = 0; j < strlen(orang); j++) {
        if (orang[j] >= 'a' && orang[j] <= 'z') {
//            cout << "test bener salah" << endl;
        }
        else{
            check = true;
        }
    }
    
    if ((check == true) || (strlen(telpon) != 6) || strlen(orang) > 10) {
//        cout << "test bener salah" << endl;
    }
    else{
        wartel.insert(pair<string, string>(orang, telpon));
    }
}
    for (k = 0; k < Q; k++) {
        cin >> searchh;
        if (wartel.find(searchh) != wartel.end()) {
            cout << wartel[searchh] << endl;
        }
        else {
            cout << "NIHIL" << endl;
        }
    }
    return 0;
}
