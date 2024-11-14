#include <bits/stdc++.h>
#define int64 long long
using namespace std;
const int maxn = 2e5 + 2;
vector<pair<int, int>> ad[maxn];
map<int, int> mp[maxn];
int rs = 1e9;

void dfs(int u, int p, int k, int d, int h) {
    mp[u][d] = h;
    for (auto [v, c] : ad[u]) {
        if (v == p) continue;
        dfs(v, u, k, d + c, h + 1);
        if (mp[v].size() > mp[u].size()) swap(mp[u], mp[v]);
        for (auto [cost, node] : mp[v]) {
            int rem = k + 2 * d - cost;
            if (mp[u].count(rem)) {
                rs = min(rs, mp[u][rem] + node - 2 * h);
            }
        }
        for (auto [cost, node] : mp[v]) {
            if (!mp[u].count(cost)) mp[u][cost] = node;
            mp[u][cost] = min(mp[u][cost], node);
        }
    }
}

int best_path(int n, int k, int h[][2], int l[]) {
    for (int i = 0; i < n - 1; i++) {
        ad[h[i][0]].push_back({h[i][1], l[i]});
        ad[h[i][1]].push_back({h[i][0], l[i]});
    }
    dfs(0, -1, k, 0, 0);
    return rs == (int)1e9 ? -1 : rs;
}

int main() {
    int n, k;
    cin >> n >> k;
    int h[n - 1][2]; 
    int l[n - 1];  
    for (int i = 0; i < n - 1; i++) {
        cin >> h[i][0] >> h[i][1] >> l[i];
    }

    int result = best_path(n, k, h, l);
    cout << result << endl;

    return 0;
}

