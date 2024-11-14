#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define all(val) val.begin(), val.end()

const int maxn = 5e5 + 4;
const int N = 18;

struct Edge {
    int u, v, l, r, id;
    int get(int x) {return u ^ v ^ x;};
    Edge(int u = 0, int v = 0, int l = 0, int r = 0, int id = 0):
        u(u), v(v), l(l), r(r), id(id) {}
};

int n, m, h[maxn], R[maxn], res[maxn];
int mx[maxn][20], nxt[maxn], up[maxn][20], par[maxn];
vector<int> adj[maxn];
vector<Edge> edges;

void dfs(int u, int p) {
    nxt[u] = u;
    for (int j = 1; j <= N; j++)
        up[u][j] = up[up[u][j - 1]][j - 1],
        mx[u][j] = max(mx[u][j - 1], mx[up[u][j - 1]][j - 1]);
    for (int i : adj[u]) {
        int v = edges[i].get(u);
        if (v == p) continue;
        par[v] = edges[i].id;
        up[v][0] = u; mx[v][0] = edges[i].l;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

pair<int,int> lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int k = h[u] - h[v], res = 0;
    for (int j = N; j >= 0; j--)
        if (k >> j & 1)
            res = max(res, mx[u][j]),
            u = up[u][j];
    if (u == v) return {res, u};
    for (int j = N; j >= 0; j--)
        if (up[u][j] != up[v][j])
            res = max({res, mx[u][j], mx[v][j]}),
            u = up[u][j], v = up[v][j];
    res = max({res, mx[u][0], mx[v][0]});
    return {res, up[u][0]};
}

int find(int x) {
    if (x != nxt[x]) nxt[x] = find(nxt[x]);
    return nxt[x];
}

void update(int u, int p, int w) {
    for (int v = find(u); h[v] > h[p] && v; v = find(up[v][0])) {
        R[par[v]] = w, nxt[v] = p;
    }
}

void Solve() {
    edges.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        for (int j = 0; j <= N; j++)
            up[i][j] = mx[i][j] = 0;
    }
    for (int i = 0, u, v, l, r; i < m; i++) {
        cin >> u >> v >> l >> r;
        edges.pb(u, v, l, r, i + 1);
        R[i + 1] = m + 1;
        if (i < n - 1) {
            adj[u].pb(i);
            adj[v].pb(i);
        }
    }
    dfs(1, 0);
    sort(all(edges),[](Edge a, Edge b) {
         return a.r < b.r;});
    for (int i = 0; i < m; i++) if (edges[i].id >= n) {
        int u = edges[i].u, v = edges[i].v;
        auto it = lca(u, v);
        edges[i].l = max(edges[i].l, it.first + 1);
        update(edges[i].u, it.second, edges[i].r);
        update(edges[i].v, it.second, edges[i].r);
    }
    for (int i = 0; i < m; i++) if (edges[i].id < n) {
        edges[i].r = min(edges[i].r, R[edges[i].id] - 1);
        if (edges[i].l > edges[i].r)
            return cout << "NO\n", void();
    }
    sort(all(edges),[](Edge a, Edge b) {
         return a.l < b.l;});
    set<pair<int,int>> mySet;
    int pos = 0;
    for (int i = 1; i <= m; i++) {
        while (pos < m && edges[pos].l <= i)
            mySet.insert({edges[pos].r, edges[pos].id}),
            pos++;
        while (!mySet.empty() && mySet.begin()->first < i)
            mySet.erase(mySet.begin());
        if (mySet.empty()) return cout << "NO\n", void();
        res[mySet.begin()->second] = i;
        mySet.erase(mySet.begin());
    }
    cout << "YES\n";
    for (int i = 1; i <= m; i++)
        cout << res[i] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        Solve();
    }}

