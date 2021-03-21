//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>

using namespace std;


int main() {
    
    int a, i, den, ta;
    int arr[101];
    
    cin >> a;
    for (i = 0; i < a; i++) {
        cin >> arr[i];
    }
    den = ta = arr[0];
    
    
    for (i = 0; i < a; i++){
            if (arr[i] > den)
                den = arr[i];
    }
    for (i = 0; i < a; i++){
            if (arr[i] < ta)
                ta = arr[i];
    }
    cout << den << " " << ta << endl;
    
    cin.get();
    return 0;
}
