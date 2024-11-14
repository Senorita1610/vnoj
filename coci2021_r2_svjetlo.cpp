#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O3,unroll-loops")
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
#define Mp          make_pair
#define sep         ' '
#define endl        '\n'
#define F	        first
#define S	        second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define kill(res)	cout << res << '\n', exit(0);
#define set_dec(x)	cout << fixed << setprecision(x);
#define fast_io     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io     freopen("input.txt", "r", stdin) ; freopen("output.txt", "w", stdout);
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ll N = 5e5 + 50;
const ll inf = 1e9 + 7;
 
ll n, dp[N][3][2], help[3][2], sz[N];
string s;
 
vector<int> adj[N];
 
void dfs(int v, int p = 0){
    int x = s[v] - '0';
    if(!x) sz[v]++;
 
    for(int u: adj[v]){
        if(u == p) continue;
        dfs(u, v); sz[v] += sz[u];
    }
    if(!sz[v]) return;
 
    dp[v][0][1-x] = dp[v][1][1-x] = dp[v][2][1-x] = 1;
 
    for(int u: adj[v]){
        if(u == p || !sz[u]) continue;
 
        for(int i = 0; i < 3; i++) for(int j = 0; j < 2; j++) help[i][j] = inf;
 
        for(int i = 0; i < 2; i++){
            help[0][i] = min({dp[v][0][1-i] + dp[u][0][1] + 1, dp[v][0][i] + dp[u][0][0] + 3});
            help[1][i] = min({dp[v][1][1-i] + dp[u][0][1] + 1, dp[v][1][i] + dp[u][0][0] + 3, dp[v][0][i] + dp[u][1][1], dp[v][0][1-i] + dp[u][1][0] + 2});
 
            //help[2][i] = min({help[2][i], dp[v][1][i] + dp[u][1][1], dp[v][1][1-i] + dp[u][1][0] + 2});
            //help[2][i] = min({help[2][i], dp[v][2][i] + dp[u][0][1], dp[v][2][1-i] + dp[u][0][0] + 2});
            //help[2][i] = min({help[2][i], dp[v][0][i] + dp[u][2][1], dp[v][0][1-i] + dp[u][2][0] + 2});
 
            help[2][i] = min({help[2][i], dp[v][1][i] + dp[u][1][1], dp[v][1][1-i] + dp[u][1][0] + 2});
            help[2][i] = min({help[2][i], dp[v][2][1-i] + dp[u][0][1] + 1, dp[v][2][i] + dp[u][0][0] + 3});
            help[2][i] = min({help[2][i], dp[v][0][1-i] + dp[u][2][1] + 3, dp[v][0][i] + dp[u][2][0] + 1});
        }
 
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                dp[v][i][j] = help[i][j];
                if(i) dp[v][i][j] = min(dp[v][i][j], dp[v][i-1][j]);
            }
        }
    }
}
 
int main(){
    fast_io;
 
    cin >> n >> s;
    s = "$" + s;
 
    int u, v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    v = 1;
    for(int i = n; i >= 1; i--) if(s[i] == '0') v = i;
 
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = inf;
 
    dfs(v);
 
    cout << dp[v][2][1];
 
}

