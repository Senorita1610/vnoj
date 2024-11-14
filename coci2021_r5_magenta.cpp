#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <string>
#include <sstream>
#include <assert.h>
#include <climits>
#include <sstream>
#include <numeric>
#include <time.h>
#include <limits.h>
#include <list>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <iomanip>
#include <complex>
#include <chrono>
#include <fstream>
#include <functional>
#include <unistd.h>
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,bmi,bmi2,lzcnt,popcnt")
#define lowbit(x) ((x) & -(x))
#define ml(a, b) ((1ll * (a) * (b)) % M)
#define tml(a, b) (a) = ((1ll * (a) * (b)) % M)
#define ad(a, b) ((0ll + (a) + (b)) % M)
#define tad(a, b) (a) = ((0ll + (a) + (b)) % M)
#define mi(a, b) ((0ll + M + (a) - (b)) % M)
#define tmi(a, b) (a) = ((0ll + M + (a) - (b)) % M)
#define tmin(a, b) (a) = min((a), (b))
#define tmax(a, b) (a) = max((a), (b))
#define iter(a) (a).begin(), (a).end()
#define riter(a) (a).rbegin(), (a).rend()
#define init(a, b) memset((a), (b), sizeof(a))
#define cpy(a, b) memcpy((a), (b), sizeof(a))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define pb emplace_back
#define mpr make_pair
#define ls(i) ((i) << 1)
#define rs(i) ((i) << 1 | 1)
#define INF 0x3f3f3f3f
#define NIF 0xc0c0c0c0
#define eps 1e-9
#define F first
#define S second
#define AC cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long llt;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llt, llt> pll;
typedef complex<double> cd;
// const int M = 998244353;
 
// random_device rm;
// mt19937 rg(rm());
// default_random_engine rg(rm());
// uniform_int_distribution<int> rd(INT_MIN, INT_MAX);
// uniform_real_distribution<double> rd(0, M_PI);
 
void db() { cerr << "\n"; }
template <class T, class... U>
void db(T a, U... b) { cerr << a << " ", db(b...); }
 
inline char gc()
{
    const static int SZ = 1 << 16;
    static char buf[SZ], *p1, *p2;
    if (p1 == p2 && (p2 = buf + fread(p1 = buf, 1, SZ, stdin), p1 == p2))
        return -1;
    return *p1++;
}
void rd() {}
template <typename T, typename... U>
void rd(T &x, U &...y)
{
    x = 0;
    bool f = 0;
    char c = gc();
    while (!isdigit(c))
        f ^= !(c ^ 45), c = gc();
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
    f && (x = -x), rd(y...);
}
 
template <typename T>
void prt(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        prt(x / 10);
    putchar((x % 10) ^ 48);
}
 
char c[10];
const int N = 1e5 + 5;
int h1[N], h2[N], *hd, to[N << 2], nxt[N << 2], ct = 1;
int d1[N], d2[N], *dp, vv;
 
inline void adeg(int u, int v)
{
    to[ct] = v, nxt[ct] = hd[u], hd[u] = ct++;
    to[ct] = u, nxt[ct] = hd[v], hd[v] = ct++;
}
 
inline void report(int x)
{
    static char ans[3][10] = {"Paula", "Marin", "Magenta"};
    printf("%s\n", ans[x]);
    exit(0);
}
 
void dfs(int u, int fa)
{
    dp[u] = dp[fa] + 1;
    for (int i = hd[u]; i; i = nxt[i])
        if (to[i] != fa)
            dfs(to[i], u);
}
 
void slv(int u, int fa)
{
    if (d2[u] && d1[u] + vv > d2[u])
        return;
    if (!d2[u])
        for (int i = hd[u]; i; i = nxt[i])
            if (!d2[to[i]])
                report(2);
    for (int i = hd[u]; i; i = nxt[i])
        if (to[i] != fa)
            slv(to[i], u);
}
 
signed main()
{
    int n, a, b, x, y;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%s", &x, &y, c);
        if (c[0] != 'c')
            hd = h1, adeg(x, y);
        if (c[0] != 'p')
            hd = h2, adeg(x, y);
    }
    {
        bool ov = 1;
        for (int i = h1[a]; i; i = nxt[i])
            if (to[i] != b)
                ov = 0;
        if (ov)
            report(1);
        if (!h2[b])
            report(0);
    }
    dp = d1, hd = h1, dfs(a, 0);
    dp = d2, hd = h2, dfs(b, 0);
    if (~(d1[b] ? d1[b] : d2[a]) & 1)
        hd = h1, vv = 0, slv(a, 0);
    else
        swap(d1, d2), hd = h2, vv = 1, slv(b, 0);
    report(!vv);
}

