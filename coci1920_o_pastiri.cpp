#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 500010;
int n, K, d[maxn], mx[maxn];
vector<int> G[maxn];
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> K;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    memset(d, -1, sizeof(d));
    queue<int> Q;
    while (K--) {
        int x;
        cin >> x;
        Q.push(x), d[x] = 0;
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : G[u]) if (!~d[v]) {
            Q.push(v), d[v] = d[u] + 1;
        }
    }
    vector<int> res;
    auto dfs = [&](auto self, int u, int fa) -> bool {
        mx[u] = -1;
        bool flag = !d[u];
        for (int v : G[u]) if (v ^ fa) {
            flag |= self(self, v, u);
            mx[u] = max(mx[u], mx[v] - 1);
        }
        if (flag && mx[u] == d[u]) flag = 0;
        if (flag && d[fa] <= d[u]) res.push_back(u), mx[u] = d[u], flag = 0;
        return flag;
    };
    dfs(dfs, 1, 0);
    cout << res.size() << "\n";
    for (int x : res) cout << x << " ";
    return 0;
}

