#include <bits/stdc++.h>

#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define int long long

#define sz(a) (int)a.size()
#define pii pair<int,int>
#define pb push_back
const long double PI = 3.1415926535897932384626433832795;
const int INF = 1000000000000000000;
const int MOD = 1000000007;
const int MOD2 = 1000000009;
const long double EPS = 1e-6;

using namespace std;

void add(int& a, int b) {
    if ((a += b) >= MOD) a -= MOD;
}

void sub(int& a, int b) {
    if ((a -= b) < 0) a += MOD;
}

const int N = 1e5 + 5;
int n, root, par[N], res[N];
int now, tin[N], tout[N], FT[N];
vector<int> g[N];

void dfs(int u) {
    tin[u] = ++now;
    for (auto v : g[u]) dfs(v);
    tout[u] = now;
}

void update(int i, int val) {
    for (; i <= n; i += i & -i) add(FT[i], val);
}

int query(int l, int r) {
    int res = 1;
    l--;
    for (; l; l -= l & -l) sub(res, FT[l]);
    for (; r; r -= r & -r) add(res, FT[r]);
    return res;
}

signed main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for1(i,1,n) {
        cin >> par[i];
        if (par[i] == 0) root = i;
        else g[par[i]].push_back(i);
    }

    dfs(root);
    for1(i,1,n) {
        int v; cin >> v;
        int x = query(tin[v], tout[v]);
        res[v] = x;
        if (par[v] != 0) update(tin[par[v]], x);
    }

    for1(i,1,n) cout << res[i] << " ";

}

