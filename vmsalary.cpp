#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, f) for(__typeof(f.begin()) i = f.begin(); i != f.end(); i++)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define getbit(x, i) ((x >> (i-1)) & 1LL)
#define onbit(x, i) (x | (1LL << (i-1)))
#define offbit(x, i) (x & ~(1 << (i-1)))
#define N 100010

int n, a[N], b[N], top, pos[N], con[N], ans[N];
vector<int> ke[N];
int q[N], t[N];
ll res;

void dfs(int u) {
    con[u] = 1;
    pos[u] = ++top;
    FOR(v, ke[u]) {
        dfs(*v);
        con[u] += con[*v];
    }
}

bool cmp(int i, int j) {
    return a[i] < a[j];
}

void update(int i) {
    for(i; i <= n; i += i & (-i)) t[i]++;
}

int get(int i) {
    int s = 0;
    for(i; i; i -= i & (-i)) s += t[i];
    return s;
}

ll C(int x) {
    return ll(x) * (x-1) / 2;
}

int main() {
    scanf("%d", &n);
    scanf("%d", a+1);
    For(v, 2, n) {
        int u, x;
        scanf("%d%d", &u, &x);
        a[v] = x;
        ke[u].pb(v);
    }
    dfs(1);
    For(i, 1, n) q[i] = i;
    sort(q+1, q+n+1, cmp);
    int i = 1;
    while (i <= n) {
        int j = i;
        while (j <= n && a[q[j]] == a[q[i]]) {
            int u = q[j];
            int sl = get(pos[u] + con[u] - 1) - get(pos[u]);
            ans[u] = sl;
            res += C(sl); j++;
        }
        For(k, i, j-1) update(pos[q[k]]);
        i = j;
    }
    cout << res;
}

