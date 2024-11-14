#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
 
struct Edge {
    int u, v, dis;
    Edge() {}
    Edge(int u, int v, int dis): u(u), v(v), dis(dis) {}
};
struct Directed_MT {
    int n, m;
    Edge edges[400];
    int vis[25], pre[25], id[25], in[25];
    void init(int n) {
        this->n = n;
        m = 0;
    }
    void addedge(int u, int v, int dis) {
        edges[m++] = Edge(u, v, dis);
    }
    int DirMt(int root) {
        int ans = 0;
        while(1) {
            for(int i = 0; i < n; i++)in[i] = INF;
            for(int i = 0; i < m; i++) {
                int u = edges[i].u, v = edges[i].v;
                if(edges[i].dis < in[v] && u != v) {
                    in[v] = edges[i].dis;
                    pre[v] = u;
                }
            }
            for(int i = 0; i < n; i++) {
                if(i == root)continue;
                if(in[i] == INF)return -1;
            }
            int cnt = 0;
            memset(id, -1, sizeof(id));
            memset(vis, -1, sizeof(vis));
            in[root] = 0;
            for(int i = 0; i < n; i++) {
                ans += in[i];
                int v = i;
                while(vis[v] != i && id[v] == -1 && v != root) {
                    vis[v] = i;
                    v = pre[v];
                }
                if(v != root && id[v] == -1) {
                    for(int u = pre[v]; u != v; u = pre[u])
                        id[u] = cnt;
                    id[v] = cnt++;
                }
            }
            if(cnt == 0)break;
            for(int i = 0; i < n; i++)
                if(id[i] == -1)id[i] = cnt++;
            for(int i = 0; i < m; i++) {
                int v = edges[i].v;
                edges[i].v = id[edges[i].v];
                edges[i].u = id[edges[i].u];
                if(edges[i].u != edges[i].v)
                    edges[i].dis -= in[v];
            }
            n = cnt;
            root = id[root];
        }
        return ans;
    }
} MT;
 
int n, k, a[30];
int cost[30][30];
 
int solve() {
    MT.init(n + 1);
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1)
            MT.addedge(n, i - 1, 0);
    }
    for(int i = 1; i <= n; i++)
        if(a[i] == 0) {
            for(int j = 1; j <= n; j++)
                if(i != j)
                    MT.addedge(j - 1, i - 1, cost[i][j]);
        }
    return MT.DirMt(n);
}
 
int main() {
    // freopen("input.inp", "r", stdin);
 
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    for(int i = 1; i <= n - k; i++)
        a[i] = 0;
    for(int i = n - k + 1; i <= n; i++)
        a[i] = 1;
    int ans = INF;
    do {
        ans = min(ans, solve());
    } while(next_permutation(a + 1, a + 1 + n));
    printf("%d\n", ans);
 
    return 0;
}

