#include <bits/stdc++.h>
#define int long long
#define MASK(i) (1ll << (i))

using namespace std;

const int N = 1e5 + 5;
const int LOG = __lg(N);

int n, q, depth[N], par[N][LOG + 5], root;
vector<int> adj[N];

void DFS(int u) {
    for (vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
        int v = *it;
        if (v != par[u][0]) {
            depth[v] = depth[u] + 1;
            par[v][0] = u;
            for (int i = 1; i <= LOG; i++) par[v][i] = par[par[v][i - 1]][i - 1];
            DFS(v);
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u];
    for (int i = 0; MASK(i) <= d; i++) if (d >> i & 1) v = par[v][i];
    if (u == v) return u;
    for (int i = LOG; i >= 0; i--) if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n) {
        if (!n) return 0;

        for (int u = 0; u < N; u++) adj[u].clear();
        memset(depth, 0, sizeof depth);
        memset(par, 0, sizeof par);
        root = 1;

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        DFS(1);
        cin >> q;
        while (q--) {
            char type;
            int u, v;
            cin >> type;
            if (type == '!') cin >> root;
            else {
                cin >> u >> v;
                cout << (LCA(u, v) ^ LCA(u, root) ^ LCA(v, root)) << "\n";
            }
        }
    }
}

