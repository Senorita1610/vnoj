#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
int n, k, goHere, root[N], h[N], par[N][21];
vector<int> adj[N], comp[N];

void preDfs(int u) {
    for (int v: adj[u]) {
        h[v] = h[u]+1;
        par[v][0] = u;

        for (int j = 1; j <= 20; j++)
            par[v][j] = par[par[v][j-1]][j-1];
        preDfs(v);
    }
}

int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int i = 0; i <= 20; i++) if ((k >> i) & 1)
            u = par[u][i];
    }
    if (u == v) return u;

    for (int i = 20; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (y == 0) goHere = i;
        adj[y].push_back(i);
        comp[x].push_back(i);
    }
    preDfs(goHere);
    for (int i = 1; i <= k; i++) {
        int root = comp[i][0], leaf = comp[i][1];
        int d = h[root] + h[leaf] - 2*h[lca(root, leaf)];
        for (int v: comp[i]) {
            int d1 = h[root] + h[v] - 2*h[lca(root, v)];
            int d2 = h[leaf] + h[v] - 2*h[lca(leaf, v)];
            if (max(d1, d2) > d) {
                d = max(d1, d2);
                if (d1 > d2) leaf = v;
                else root = v;
            }
        }
        cout << d << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}

