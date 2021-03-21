//
//  main.cpp
//  Duck
//
//  Created by Denta Bramasta Hidayat on 08/03/21.
//

#include <cstdio>

int N, arr[105];

int main() {
  while (scanf("%d", &arr[N]) != EOF) {
    N++;
  }
    for (N = N-1; N >= 0; N--) {
        printf("%d\n", arr[N]);
    }
}
