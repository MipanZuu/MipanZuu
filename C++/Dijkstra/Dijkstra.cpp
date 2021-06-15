//
//  main.cpp
//  Dijkstra
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//

#include <bits/stdc++.h>
using namespace std;
int n;
int mat[105][105];
int arrPrev[100];
int arrDist[100];

int minDistance(int arrDist[], bool setQ[]) {
    
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
    if (setQ[v] == false && arrDist[v] <= min)
        min = arrDist[v], min_index = v;
   
    return min_index;
}

void dijkstra(int src){
    bool setQ[n];
    
    for (int i = 0; i < n; i++){
        arrDist[i] = INT_MAX;
        setQ[i] = false;
        arrPrev[i] = -1;
    }
    arrDist[src] = 0;
        
    for (int vertices = 0; vertices < n-1; vertices++){
            int u = minDistance(arrDist, setQ);
            setQ[u] = true;
        for (int v = 0; v < n; v++) {
            int alt = arrDist[u] + mat[u][v];
            if (alt < arrDist[v]) {
                arrDist[v] = alt;
                arrDist[v] = u;
            }
        }
    }
}

void findpath (int target){
    stack <int> pathTaken;
    cout << endl << "total shortest dist = " << arrDist[target] << endl;
    pathTaken.push(target);
    while (pathTaken.top()!=0) {
        pathTaken.push(arrPrev[target]);
        target = arrPrev[target];
    }
    while (!pathTaken.empty()) {
        cout << pathTaken.top();
        if (pathTaken.size()!=1) {
            cout << " -> ";
        }
        pathTaken.pop();
    }
}



int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    dijkstra(0);
    int target;
    cin >> target;
    findpath(target);
    return 0;
}


//example input

/*
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
