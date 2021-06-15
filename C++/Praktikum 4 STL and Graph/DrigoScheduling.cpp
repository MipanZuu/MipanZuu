//
//  main.cpp
//  Praktikum modul 4 Graf
//
//  Created by Denta Bramasta Hidayat on 24/05/21.
//

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
         int T,N,i,m,n,counter,prevend;
         cin>>T;
         while(T--)
        {
            cin>>N;
            pair<int,int> schedule[N];
            for(i = 0; i < N; i++){
            cin >> m >> n;
                schedule[i]=make_pair(n,m);
        }
        sort(schedule,schedule+N);
        counter = 0;
        prevend = -1;
        for(i = 0; i < N ; i++)
            if(schedule[i].second>=prevend){
            counter++;
            prevend=schedule[i].first;
            }
            cout << counter << endl;
         }
        return 0;
}
