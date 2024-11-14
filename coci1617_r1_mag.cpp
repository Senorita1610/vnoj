#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define           f     first
#define           s     second
#define           pb    push_back
#define           ep    emplace
#define           eb    emplace_back
#define           lb    lower_bound
#define           ub    upper_bound
#define       all(x)    x.begin(), x.end()
#define      rall(x)    x.rbegin(), x.rend()
#define   uniquev(v)    sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define     mem(f,x)    memset(f , x , sizeof(f))
#define        sz(x)    (ll)(x).size()
#define  __lcm(a, b)    (1ll * ((a) / __gcd((a), (b))) * (b))
#define          mxx    *max_element
#define          mnn    *min_element
#define    cntbit(x)    __builtin_popcountll(x)
#define       len(x)    (int)(x.length())
 
const int N = 1e6 + 10;
ll a[N];
int down[N], up[N], p[N];
vector <int> ed[N];
 
void dfs(int u, int v) {
    if (a[u] == 1)
        down[u] = 1;
 
    up[u] = 1;
    p[u] = v;
 
    int m1 = 0, m2 = 0;
    for (auto x : ed[u]) {
        if (x == v)
            continue;
 
        dfs(x, u);
        if (a[u] == 1) {
            down[u] = max(down[u], down[x] + 1);
        }
    }
}
 
void dfs2(int u, int v) {
    int m1 = 0, m2 = 0;
    for (auto x : ed[u]) {
        if (x == v)
            continue;
 
        if (m1 < down[x]) {
            m2 = m1;
            m1 = down[x];
        } else {
            m2 = max(m2, down[x]);
        }
    }
 
    for (auto x : ed[u]) {
        if (x == v)
            continue;
        
        if (a[u] == 1) {
            if (down[x] == m1) {
                up[x] = max(up[u] + 1, m2 + 2);
            } else {
                up[x] = max(up[u] + 1, m1 + 2);
            }
        }
 
        dfs2(x, u);
    }
}
 
ll solve() {
    int n;
    cin >> n;
 
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ed[a].pb(b);
        ed[b].pb(a);
    }
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    dfs(1, 1);
    dfs2(1, 1);
 
    ll x = -1, y = 1;
    for (int i = 1; i <= n; i++) {
        int m1 = 0, m2 = 0;
        for (auto x : ed[i]) {
            if (x == p[i])
                continue;
 
            if (m1 < down[x]) {
                m2 = m1;
                m1 = down[x];
            } else {
                m2 = max(m2, down[x]);
            }
        }
 
        ll len = max(m1 + m2 + 1, up[i] + m1);
        if (x == -1 || (x * len > a[i] * y)) {
            x = a[i];
            y = len;
        }
    }
 
    ll g = __gcd(x, y);
    cout << x / g << "/" << y / g << '\n';
 
    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
 
    int t = 1;
    //cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}

