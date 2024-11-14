#include <bits/stdc++.h>

using namespace std;

#define fo(i, a, b) for(int i = a; i <= b; i++)
#define _fo(i, a, b) for(int i = a; i >= b; i--)
#define foa(i, a) for (auto &i : a)
#define sz(a) ((int) a.size())
#define all(a) begin(a), end(a)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mk(x, y) make_pair(x, y)

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 5e5+5;
const int LOG = 20;
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ll SQRT = 4e6;

int n, m;
int f[MAX];
vector<int> adj[MAX];
int color[MAX];

void dfs(int v) {
    f[v] = 0;
    foa(u, adj[v]) {
        if(f[u] == -1) dfs(u);
        f[v] = max(f[v], f[u]+1);
    }
}

bool cycle(int v) {
    if(color[v] == 1) return true;      
    color[v] = 1;
    foa(u, adj[v]) {
        if(color[u] == 2) continue;
        if(cycle(u)) return true;
    }
    color[v] = 2;
    return false;
}

bool check() {
    fo(v, 1, n) {
        if(cycle(v)) return false;
    }
    return true;
}

signed main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fo(i, 1, m) {
        int v, u;
        cin >> v >> u;
        adj[v].pb(u);
    }

    if(!check()) cout << -1;
    else {
        fill(f, f+n+1, -1); 
        fo(i, 1, n) {
            if(f[i] == -1) dfs(i);
        }
        int res = 0;
        fo(i, 1, n) res = max(res, f[i]);
        cout << res+1;  
    }
}

