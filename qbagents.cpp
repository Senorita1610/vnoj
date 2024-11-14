#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <set>

using namespace std;

const int maxN = 251;
const int maxQ = 1000001;
const int inf  = 60001;

struct tqueue {
    int front, rear, nitem;
    int itemx[maxQ], itemy[maxQ], itemz[maxQ]; 
} q;

int N, s, t, M, G[maxN][maxN], dp[maxN][maxN][2];

void push(int x, int y, int z) {
    q.front = (q.front + 1) % maxQ;
    q.nitem++;
    q.itemx[q.front] = x;
    q.itemy[q.front] = y;
    q.itemz[q.front] = z;
}

void pop(int &x, int &y, int &z) {
    q.nitem--;
    x = q.itemx[q.rear];
    y = q.itemy[q.rear];
    z = q.itemz[q.rear];
    q.rear = (q.rear + 1) % maxQ;
}

int main(int argc, char **argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif ONLINE_JUDGE 
    
    q.nitem = 0,    q.front = 0,    q.rear = 1;
    cin >> N >> M >> s >> t;
    for (int i = 1; i <= N; i++) G[i][0] = 0;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        G[u][0]++;
        G[u][G[u][0]] = v;
    }
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) 
            for (int z = 0; z <= 1; z++)
                dp[i][j][z] = inf;
    dp[s][t][1] = 0;    push(s, t, 1);
    
    int x, y, z;
    do {
        pop(x, y, z);
        if (!z) {
            for (int i = 1; i <= G[x][0]; i++) 
                if (dp[x][y][z] + 1 < dp[G[x][i]][y][1]) {
                    dp[G[x][i]][y][1] = dp[x][y][z] + 1;
                    push(G[x][i], y, 1);
                }
        } else {
            for (int i = 1; i <= G[y][0]; i++)
                if (dp[x][y][z] + 1 < dp[x][G[y][i]][0]) {
                    dp[x][G[y][i]][0] = dp[x][y][z] + 1;
                    push(x, G[y][i], 0);
                }
        }
    } while (q.nitem);
    
    int mind = inf;
    for (int i = 1; i <= N; i++) 
        mind = min(dp[i][i][1], mind);
    if (mind == inf) cout << "-1"; else cout << mind/2;
    
    return 0;
}

