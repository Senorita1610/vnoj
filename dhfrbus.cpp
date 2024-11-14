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
#define bit(x, i) ((x >> i) & 1LL)
#define onbit(x, i) (x | (1LL << i))
#define N 100010
#define inf 1000000000000000LL

struct node {
    ll val; int u, p;
    node(ll _val, int _u, int _p) {
        val = _val; u = _u; p = _p;
    }
};

bool operator > (node a, node b) {
    return a.val > b.val;
}

int n, m, s, t, k;
vector<ii> ke[N];
priority_queue<node, vector<node>, greater<node> > heap;
ll f[N][6];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> s >> t;
    REP(i, m) {
        int u, v, l; cin >> u >> v >> l;
        ke[u].pb(ii(v, l));
        ke[v].pb(ii(u, l));
    }
    For(i, 1, n) For(j, 0, k) f[i][j] = inf;
    f[s][0] = 0;
    heap.push(node(0, s, 0));
    while (!heap.empty()) {
        ll val = heap.top().val;
        int u = heap.top().u, p = heap.top().p;
        heap.pop();
        if (val == f[u][p]) {
            if (u == t) {
                cout << val;
                return 0;
            }
            FOR(it, ke[u]) {
                int v = it->fi, l = it->se;
                if (f[v][p] > f[u][p] + l) {
                    f[v][p] = f[u][p] + l;
                    heap.push(node(f[v][p], v, p));
                }
                if (p < k && f[v][p+1] > f[u][p]) {
                    f[v][p+1] = f[u][p];
                    heap.push(node(f[v][p+1], v, p+1));
                }
            }
        }
    }
}

