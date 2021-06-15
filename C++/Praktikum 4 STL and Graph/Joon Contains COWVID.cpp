//
//  main.cpp
//  Praktikum modul 4 Graf
//
//  Created by Denta Bramasta Hidayat on 24/05/21.
//

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;



int n;
vector<int> adj[maxn];

int dfs(int start, int parent) {
    int counter = 0;
    int sz = adj[start].size();
    if (parent == -1) {
        
        //parent node is currently root node
        sz++;
    }
    int currentCows = 1;
    int days = 0;
    
    //count the number of superspreader events needed
    while (currentCows < sz) {
        days++;
        currentCows *= 2;
    }

    counter += days;

    for (auto next : adj[start]) {
        if (next != parent) {
            counter += dfs(next, start) + 1;
        }
    }
    return counter;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int answer = dfs(0, -1);
    cout << answer << endl;
    return 0;
}

