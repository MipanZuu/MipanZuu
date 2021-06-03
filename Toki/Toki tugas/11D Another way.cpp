//
//  main.cpp
//  Another way 11D
//
//  Created by Denta Bramasta Hidayat on 03/06/21.
//

#include <bits/stdc++.h>
    using namespace std;
    int ances[200], dep[200];
    vector < pair< int, pair< int, int >>> edge;

    int find(int x){
        if (ances[x]==x) return x;
        else{
            ances[x]=find(ances[x]);
            return ances[x];
        }
    }
        
        bool check(int x, int y) {
        x=find(x), y=find(y);
        if(x==y)return 1;
        else return 0;
    }

    void merge(int x, int y){
        x=find(x),y=find(y);
        if(!check(x,y)){
            if(dep[x]>dep[y]){
                ances [y]=x;
            }
            else{
                ances[x]=y;
                dep[y]++;
            }
        }
    }

int main(){
    int N;
    cin>>N;
    for(int a = 0; a < N; a++){
        ances[a]=a;
        dep[a]=1;
    }
        for(int a = 0; a < N; a++){
            for(int b = 0; b < N; b++){
                int val;
                cin >> val;
                edge.push_back(make_pair(val,make_pair(a,b)));
            }
        }
        int total=0;
        sort(edge.begin(), edge.end());
        for(auto a: edge) {
            if(!check(a.second.first,a.second.second)){
                merge(a.second.first,a.second.second);
                total+=(a.first);
            }
        }
        cout << total << endl;
    }
