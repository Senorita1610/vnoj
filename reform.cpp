#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int n, m, timer, cnt;
int num[N], low[N], used[N], nChild[N];
pair<int, int> edge[N];
vector<int> adj[N];
vector<long long> res;
long long ans;

int dfs(int u) {
    timer++;
    low[u] = n+1;
    num[u] = timer;
    nChild[u] = 1;

    for (int i: adj[u]) if (!used[i]) {
        used[i] = timer;

        int v = edge[i].first+edge[i].second-u;
        if (num[v] == 0) {
            dfs(v);
            nChild[u] += nChild[v];
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) {
                cnt++;
                ans += 1ll*nChild[v]*(n-nChild[v])-1;
            }
        }
        else low[u] = min(low[u], num[v]);
    }
    return nChild[u];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edge[i] = {u, v};
    }

    timer = 0;
    for (int i = 1; i <= n; i++)
        if (num[i] == 0) res.push_back(dfs(i));

    int sz = (int) res.size();
    if (sz > 2) cout << 0;
    if (sz == 2) cout << 1ll*(m-cnt)*1ll*res[0]*1ll*res[1];
    if (sz == 1) cout << 1ll*(m-cnt)*(1ll*n*(n-1)/2-m)+ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}

