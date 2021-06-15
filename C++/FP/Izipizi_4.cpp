//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//


#include <bits/stdc++.h>
using namespace std;

int dijX[] = {-1, 0, 1, 0};
int dijY[] = {0, 1, 0, -1};

struct Edge
{
    int r, c;
    int cost;
    bool operator>(const Edge &e) const
    {
        return this->cost > e.cost;
    }
};

int main()
{
    int Q;
    cin >> Q;
    while ( Q-- )
    {
        int N, M;
        cin >> N >> M;

        vector<vector<int> > query(N, vector<int>(M));
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < M; ++c)
                cin >> query[r][c];

        priority_queue<Edge, vector<Edge>, greater<Edge> > Pque;
        vector<vector<int> > cost(N, vector<int>(M, -1));

        Edge edg;
        edg.r = 0;
        edg.c = 0;
        edg.cost = query[0][0];
        Pque.push(edg);
        cost[0][0] = edg.cost;
        while (!Pque.empty())
        {
            Edge u = Pque.top();
            Pque.pop();
            for (int i = 0; i < 4; ++i)
            {
                int r = u.r + dijX[i];
                int c = u.c + dijY[i];
                if (r < 0 || r >= N || c < 0 || c >= M)
                    continue;
                if (cost[r][c] == -1 || cost[u.r][u.c] + query[r][c] < cost[r][c])
                {
                    cost[r][c] = cost[u.r][u.c] + query[r][c];
                    edg.r = r;
                    edg.c = c;
                    edg.cost = cost[r][c];
                    Pque.push(edg);
                }
            }
        }
        cout << cost[N - 1][M - 1] << endl;
    }
    return 0;
}
