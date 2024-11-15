#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1 << x)
#define bit(x, i) ((x >> i) & 1)
#define onbit(x, i) (x | (1 << i))
#define N 70010

int n, tin[N], tout[N], f[N][20], vmax, timer, ntest, p[N][20];
vector<int> ke[N];
int cha[N];

void input() {
    scanf("%d%d", &n, &ntest);
    For(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }
}

void dfs(int u) {
    tin[u] = ++timer;
    For(j, 1, vmax) f[u][j] = f[f[u][j-1]][j-1];
    For(j, 0, sz(ke[u])-1) {
        int v = ke[u][j];
        if (!cha[v]) {
            cha[v] = u; f[v][0] = u;
            dfs(v);
        }
    }
    tout[u] = ++timer;
}

bool ispa(int u, int v) {
    if (tin[u] <= tin[v] && tout[u] >= tout[v]) return true;
    return false;
}

int lca(int u, int v) {
    if (ispa(u, v)) return u;
    if (ispa(v, u)) return v;
    Rep(j, vmax, 0)
        if (!ispa(f[u][j], v)) u = f[u][j];
    return cha[u];
}

void init() {
    cha[1] = 1; f[1][0] = 1;
    vmax = trunc(log(n) / log(2));
    dfs(1);
}

void sub1() {
    while (ntest) {
        ntest--;
        int u, v; scanf("%d%d", &u, &v);
        For(i, u+1, v) u = lca(u, i);
        printf("%d\n", u);
    }
}

int get(int i, int j) {
    int k = trunc(log(j-i+1) / log(2));
    return lca(p[i][k], p[j - two(k) + 1][k]);
}

void sub2() {
    For(i, 1, n) p[i][0] = i;
    For(j, 1, vmax)
        For(i, 1, n - two(j) + 1)
            p[i][j] = lca(p[i][j-1], p[i + two(j-1)][j-1]);
    while (ntest) {
        ntest--;
        int u, v;
        scanf("%d%d", &u, &v);
        int pp = get(u, v);
        printf("%d\n", pp);
    }
}

int main() {
    input();
    init();
    if (n <= 1000 && ntest <= 1000) sub1(); else
    sub2();
}

