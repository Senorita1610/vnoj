#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pill pair<int,ll>
#define mem(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define name "test"
 
using namespace std;
 
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const ll oo = 1e18;
 
template <typename T1, typename T2> bool maxi(T1 &a, T2 b){if (a < b){a = b; return 1;} return 0;}
template <typename T1, typename T2> bool mini(T1 &a, T2 b){if (a > b){a = b; return 1;} return 0;}
 
int n;
int m;
int q;
int a[N];
int cnt[N];
ll g[N][3];
ll f[N][N][3];
ll dp[N];
bool vst[N];
vector<int> adj[N];
 
void load(){
    cin.tie(0)->sync_with_stdio(0);
}
 
void input(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
}
 
void merge_node(int u, int v){
    for (int i = 0; i <= cnt[u] + cnt[v] + 2; i++)
        for (int x = 0; x < 3; x++)
            g[i][x] = oo;
    for (int i = 0; i <= cnt[u]; i++)
        for (int j = 0; j <= cnt[v]; j++){
            for (int x = 0; x < 3; x++){
                mini(g[i + j][0], f[u][i][0] + f[v][j][x]);
                mini(g[i + j][1], f[u][i][1] + f[v][j][x]);
                mini(g[i + j][2], f[u][i][2] + f[v][j][x]);
            }
            mini(g[i + j + 2][2], f[u][i][1] + f[v][j][1]);
            mini(g[i + j + 1][2], f[u][i][1] + f[v][j][2]);
            mini(g[i + j + 1][2], f[u][i][2] + f[v][j][1]);
        }
    cnt[u] += cnt[v];
    for (int i = cnt[u]; i >= 0; i--)
        for (int x = 0; x < 3; x++){
            mini(f[u][i][x], g[i][x]);
            if (i < cnt[u]) mini(f[u][i][x], f[u][i + 1][x]);
        }
}
 
void dfs(int u, int pre){
    vst[u] = 1;
    cnt[u] = 1;
    f[u][0][0] = 0;
    f[u][0][1] = a[u];
    for (int v : adj[u]) if (v != pre){
        dfs(v, u);
        merge_node(u, v);
    }
}
 
void solve(){
    mem(f, 0x3f);
    vector<int> root;
    mem(dp, 0x3f);
    dp[0] = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        if (!vst[i]){
            dfs(i, 0);
            for (int j = cnt[i]; j >= 0; j--){
                mini(f[i][j][0], f[i][j][1]);
                mini(f[i][j][0], f[i][j][2]);
                if (j < cnt[i]) mini(f[i][j][0], f[i][j + 1][0]);
            }
            sum += cnt[i];
            for (int j = sum; j >= 0; j--){
                for (int k = 1; k <= cnt[i]; k++){
                    if (j >= k){
                        mini(dp[j], dp[j - k] + f[i][k][0]);
                    }
                }
            }
        }
    }
    while (q--){
        ll S; cin >> S;
        int ans = 0;
        int l = 0;
        int r = n;
        while (l <= r){
            int m = (l + r) >> 1;
            if (dp[m] <= S){
                maxi(ans, m);
                l = m + 1;
            } else r = m - 1;
        }
        cout << ans << '\n';
    }
}
 
int main(){
    load();
    input();
    solve();
}

