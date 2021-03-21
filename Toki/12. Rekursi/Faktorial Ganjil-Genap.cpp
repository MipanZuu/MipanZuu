//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>

using namespace std;

int fac(int N){
    if (N == 1) {
        return 1;
    }
    else if (N%2 == 0) {
        return (N/2) * fac(N-1);
    }else{
        return N * fac(N-1);
    }
}

int main (){
    int faktorial, a;
    cin >> faktorial;
    a = fac(faktorial);
    cout << a << endl;
}
