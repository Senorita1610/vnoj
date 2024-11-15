#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <time.h>
#include <assert.h>
#include <iomanip>
#include <cstring>
#include <queue>
#define ll long long
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define BIT(x, i) (1 & ((x) >> (i)))
#define OFF(x, i) ((x) ^ (1 << (i)))
#define ON(x, i) ((x) | (1 << (i)))
#define CNT(x) __builtin_popcountll(x)
#define file(name)                         \
    if (fopen(name ".inp", "r"))           \
    {                                      \
        freopen(name ".inp", "r", stdin);  \
        freopen(name ".out", "w", stdout); \
    }
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
const ll N = 200000;
ll n;
ll u[N], v[N], w[N], z[N];
ll vis[N], par[N], rnk[N], p[N], dp[N];
vector<ll> g[N];
ll fnd(ll x) { return x == par[x] ? x : par[x] = fnd(par[x]); }
ll dfs(ll c)
{
    ll ret = 0;
    vis[c] = 1, p[c] = par[c] = c, dp[c] = 1 + (c && c < n - 1);
    for (ll i = c - 1; i <= c + 1; i += 2)
        if (i >= 0 && i < n && vis[i])
            dp[p[fnd(i)]] -= 2;
    for (ll i : g[c])
        if (!vis[c ^ u[i] ^ v[i]])
        {
            if (u[i] != c)
                swap(u[i], v[i]);
            ret += dfs(v[i]), dp[c] += dp[v[i]];
            ret += min(w[i] * dp[v[i]], z[i]);
            ll x = fnd(c), y = fnd(v[i]);
            if (rnk[x] < rnk[y])
                swap(x, y);
            rnk[x] += rnk[x] == rnk[y], par[y] = x, p[x] = c;
        }
    return ret;
}
 
main()
{
    faster;
    file("tmp");
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> u[i] >> v[i] >> w[i] >> z[i];
        g[--u[i]].push_back(i);
        g[--v[i]].push_back(i);
    }
    cout << dfs(0);
    return 0;
}

