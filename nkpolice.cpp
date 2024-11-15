#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef pair <int, int> ii;
typedef pair <ii, int> II;
#define fi first
#define se second

int n, m, t, q, cnt, low[N], num[N], st[N], en[N], h[N];
vector <ii> G[N];
vector <ii> val[N], d[N];
bool cr[N];

inline void dfs(int u, int p) {
    int ch = 0;
    low[u] = num[u] = ++t; st[u] = ++cnt;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i].se, id = G[u][i].fi; if (v == p) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            ++ch, h[v] = h[u] + 1, dfs(v, u), low[u] = min(low[u], low[v]);
            if (u == p && ch >= 2) cr[u] = 1;
            else if (u != p && low[v] >= num[u]) cr[u] = 1;
        }
    }

    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i].se; if (v == p) continue;
        if (u == p && ch >= 2) d[u].push_back(ii(st[v], en[v]));
        else if (u != p && low[v] >= num[u]) d[u].push_back(ii(st[v], en[v]));
    }

    sort(d[u].begin(), d[u].end());
    int l = 0, r = 0;
    for (int i = 0; i < d[u].size(); i++) {
        if (d[u][i].fi > r) {
            if (i > 0) val[u].push_back(ii(l, r));
            l = d[u][i].fi, r = d[u][i].se;
        }
        else r = max(r, d[u][i].se);
    }
    if (l && r) val[u].push_back(ii(l, r));

    en[u] = cnt;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(ii(i, v)); G[v].push_back(ii(i, u));
    }
    for (int i = 1; i <= n; i++) if (!num[i]) dfs(i, i);
    cin >> q;
    while(q--) {
        int type; cin >> type;
        if (type == 1) {
            int a, b, g1, g2; cin >> a >> b >> g1 >> g2;
            if (h[g1] != h[g2] + 1 && h[g2] != h[g1] + 1) { printf("yes\n"); continue; }
            bool br = 0;
            if (h[g1] == h[g2] - 1) swap(g1, g2);
            if (low[g1] >= num[g1]) br = 1;
            if (!br) { printf("yes\n"); continue; }
            if ( (st[g1] <= st[a] && st[a] <= en[g1]) == (st[g1] <= st[b] && st[b] <= en[g1]) ) printf("yes\n");
            else printf("no\n");
        }

        else {
            int a, b, c; cin >> a >> b >> c;
            if (!cr[c]) { printf("yes\n"); continue; }
            int inA = 0, inB = 0;
            inA = upper_bound(val[c].begin(), val[c].end(), ii(st[a], N+N)) - val[c].begin();
            inB = upper_bound(val[c].begin(), val[c].end(), ii(st[b], N+N)) - val[c].begin();

            if (inA && inA <= val[c].size() && !(val[c][inA-1].fi <= st[a] && st[a] <= val[c][inA-1].se)) inA = 0;
            if (inB && inB <= val[c].size() && !(val[c][inB-1].fi <= st[b] && st[b] <= val[c][inB-1].se)) inB = 0;

            if (inA == inB) printf("yes\n");
            else printf("no\n");
        }
    }
}

