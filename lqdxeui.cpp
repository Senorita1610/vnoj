#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<pair<int, int>>> c;
vector<int> f;

void dfs(int u, int par) {
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i].first;
        int cost = c[u][i].second;
        if (v == par)
            continue;
        f[v] = f[u] + cost;
        dfs(v, u);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, u, v, cc, two_way_cost = 0;
    cin >> n >> x;
    c.resize(n + 1);
    f.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> cc;
        c[u].push_back({v, cc});
        c[v].push_back({u, cc});
        two_way_cost += (cc * 2);
    }
    f[x] = 0;
    dfs(x, 0);
    int uMax = 1;
    for (int i = 1; i <= n; i++) {
        if (f[uMax] < f[i])
            uMax = i;
    }
    f[uMax] = 0;
    dfs(uMax, 0);
    uMax = 1;
    for (int i = 1; i <= n; i++) {
        if (f[uMax] < f[i])
            uMax = i;
    }
    cout << two_way_cost - f[uMax];

    return 0;
}

