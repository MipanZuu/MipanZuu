//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <iostream>
using namespace std;

int main() {
    int N, M;
    int matriks[105][105];
    
    cin >> N >> M;
    
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        cin >> matriks[i][j];
       
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = N-1; j >= 0; j--) {
        
        cout << matriks [j][i];
        
    if (j != 0) {
        cout << " ";
    }else{
        cout << endl;
    }
  }
 }
}
