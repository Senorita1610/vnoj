#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int m, n;
char a[505][505];
int dist[505][505], vs[505][505];

int main() {
    scanf("%d%d", &m, &n);
    gets(a[0]);
    for(int i=0;i<m;++i) gets(a[i]);
    queue<PII> q;
    PII st, en;
    memset( dist, 0x1f, sizeof(dist));
    for(int i=0;i<m;++i) for(int j=0;j<n;++j) 
        if(a[i][j] == '+') {
            q.push(make_pair(i,j));
            dist[i][j] = 0;
        }
        else if(a[i][j] == 'V')
            st = make_pair(i,j);
        else if(a[i][j] == 'J')
            en = make_pair(i,j);
    while(!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for(int h=0;h<4;++h) {
            int x = u + dx[h];
            int y = v + dy[h];
            if(0 <= x && x < m && 0 <= y && y < n && dist[x][y] > dist[u][v] + 1) {
                dist[x][y] = dist[u][v] + 1;
                q.push(make_pair(x,y));
            }
        }
    }
    int L = 0, R = 1010;
    while(L < R) {
        int M = (L+R) / 2 + 1;
        memset( vs, 0, sizeof(vs));
        while(!q.empty()) q.pop();
        if(dist[st.first][st.second] >= M) {
            vs[st.first][st.second] = true;
            q.push(st);
        }
        while(!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            for(int h=0;h<4;++h) {
                int x = u + dx[h];
                int y = v + dy[h];
                if(0 <= x && x < m && 0 <= y && y < n && !vs[x][y] && dist[x][y] >= M) {
                    vs[x][y] = true;
                    q.push(make_pair(x,y));
                }
            }
        }
        if(vs[en.first][en.second]) L = M;
        else R = M - 1;
    }
    cout << L << endl;
    return 0;
}

