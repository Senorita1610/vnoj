#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> ii;
struct data {
        int u, x;
        double d;
        data(int u, int x, double d) {
                this -> u = u;
                this -> x = x;
                this -> d = d;
        }
        bool operator < (const data &other) const {
                return d > other.d;
        }
};
const int N = 2e3, M = 2e5, K = 15, C = 2e6;
const double INF = 1e9;
int m, n, k, u, v, c, x, dist[N][K];
vector <ii> a[N];
double d[N][K];
priority_queue<data> Heap;
void Dijkstra() {
        for (int i = 2; i <= n; i++)
                for (int j = 0; j <= k; j++)
                        d[i][j] = INF;
        for (int j = 0; j <= k; j++) Heap.push(data(1, j, d[1][j]));
        for (;;) {
                data top = Heap.top();  Heap.pop();
                u = top.u;      x = top.x;      dist[u][x] = 1;
                if (d[u][x] != top.d) continue;
                if (u == n && x == k) break;
                for (int i = 0; i < a[u].size(); i++) {
                        v = a[u][i].x;
                        double c = a[u][i].y;
                        int sl = 1;
                        for (int j = x; j <= k; j++) {
                                if (!dist[v][j] && d[v][j] > d[u][x] + c/sl) {
                                        d[v][j] = d[u][x] + c/sl;
                                        Heap.push(data(v, j, d[v][j]));
                                }
                                sl *= 2;
                        }
                }
        }
}

int main() {
        cin >> n >> m >> k;
        for (int i = 1; i <= m; i++) {
                cin >> u >> v >> c;
                a[u].push_back(ii(v, c));
                a[v].push_back(ii(u, c));
        }
        Dijkstra();
        printf("%.2lf", d[n][k]);
}

