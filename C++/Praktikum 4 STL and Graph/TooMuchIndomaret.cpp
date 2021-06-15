//
//  main.cpp
//  Praktikum modul 4 Graf
//
//  Created by Denta Bramasta Hidayat on 24/05/21.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int L,N;
    pair<int, int> indomaret[10000];
    
    while(true){
        scanf("%d %d",&L,&N);
        
        if(L == 0) break;
        
        for(int i = 0,x,r;i < N;++i){
            scanf("%d %d",&x,&r);
            indomaret[i] = make_pair(x - r,x + r);
        }
        
        sort(indomaret, indomaret + N);
        int pos = 0, aux, i = 0,ans = N;
        
        while(pos < L){
            aux = pos;
            
            while(i < N && indomaret[i].first <= pos)
                aux = max(aux,indomaret[i++].second);
            
            if(aux == pos) break;
    
            pos = aux;
            --ans;
        }
        
        printf("%d\n",pos < L? -1 : ans);
    }
    
    return 0;
}

