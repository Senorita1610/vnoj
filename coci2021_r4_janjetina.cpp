#include <bits/stdc++.h>
using namespace std;
 
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
 
#define lx (id << 1)
#define rx (lx | 1)
#define gcd __gcd
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define bit(i, mask) ((mask) >> (i) & 1)
#define reset(x, val) memset(x, val, sizeof(x))
#define foru(i,a,b) for(int i = (a); i <= (b); ++i)
#define ford(i,a,b) for(int i = (a); i >= (b); --i)
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
template<typename T> bool maximize(T &res, const T &val) { if (res < val) { res = val; return true; } return false; }
template<typename T> bool minimize(T &res, const T &val) { if (val < res) { res = val; return true; } return false; }
 
const ll Linf = 0x3f3f3f3f3f3f3f3f;
const int Inf = 0x3f3f3f3f;
const ll Mod = 1e9 + 7;
const ll Mod2 = ll(1e9) + 9;
const int Lim = 1e6 + 5;
const int inv6 = 166666668;
 
/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
 
const int base = 3;
const int N = 1e5 + 5;
const int K = log2(N) + 1;
const int dx[] = {+1, -1, 0, 0};
const int dy[] = {0, 0, +1, -1};
const int block_size = sqrt(2e9) + 2;
 
int n, k;
int sz[N], f[N];
vector<pii> adj[N];
 
struct Fenwick {
    vector<int> f;
    int n = 0;
 
    Fenwick(int n = 0): n(n) { f.assign(n + 1, 0); }
    void upd(int u, int x) { for (; u <= n; u += u & -u) f[u] += x; }
    int get(int u) { u = min(u, n); int ans = 0; for (; u > 0; u -= u & -u) ans += f[u]; return ans; }
};
 
int dfs_sz(int u, int p) {
    sz[u] = 1;
    for (auto &[v, w]: adj[u]) if (v != p && !f[v])
        sz[u] += dfs_sz(v, u);
    return sz[u];
}
 
int find_centroid(int u, int p, int n) {
    for (auto &[v, w]: adj[u]) if (v != p && !f[v])
        if (sz[v] * 2 > n) return find_centroid(v, u, n);
    return u;
}
 
ll ans;
int nsz;
map<int, Fenwick> dp;
 
int dist[N], high[N], top[N];
vector<int> prior;
 
void dfs(int u, int p) {
    if (p) high[u] = high[p] + 1; else high[u] = 0;
    maximize(nsz, high[u]);
 
    if (p) prior.emplace_back(u);
    for (auto &[v, w]: adj[u]) if (v != p && !f[v]) {
        dist[v] = max(dist[u], w);
 
        if (p == 0) {
            top[v] = v;
        } else {
            top[v] = top[u];
        }
 
        dfs(v, u);
    }
}
 
void solve(int u) {
    dist[u] = 0;
    high[u] = 0;
 
    nsz = 0;
    prior.clear();
    dfs(u, 0);
    stable_sort(all(prior), [&](int x, int y) {
        return dist[x] < dist[y];
    });
 
    Fenwick sum(nsz);
    for (auto &u: prior) {
        int w = dist[u];
        if (high[u] == 1) {
            dp[u] = Fenwick(nsz);
        }
 
        int p = top[u];
 
        //cout << u << " " << p << " " << w << " " << high[u] << " ";
        if (w - high[u] >= k) {
            ++ans;
            //cout << " + " << 1 << ", ";
        } //cout << " + " << sum.get(w - high[u] - k) - dp[p].get(w - high[u] - k) << "\n";
        
        ans += sum.get(w - high[u] - k) - dp[p].get(w - high[u] - k);
 
        sum.upd(high[u], 1);
        dp[p].upd(high[u], 1);
    }
 
    dp.clear();
}
 
void build(int u) {
    int n = dfs_sz(u, -1);
    u = find_centroid(u, -1, n);
 
    solve(u);
 
    f[u] = true;
    for (auto &[v, w]: adj[u]) if (!f[v]) build(v);
    f[u] = false;
}
 
void solve() {
    cin >> n >> k;
    foru(i, 2, n) {
        int u, v, w;
        cin >> u >> v >> w;
 
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
 
    build(1);
    cout << ans * 2;
}
 
signed main() {
    FastIO;
    solve();
    cout << "\n";
    return 0;
}

