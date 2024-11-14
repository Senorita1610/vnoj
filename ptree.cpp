#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<ll,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 2e2 + 5;
const int INF =1e9+9;
int n, p,c[N],dp[N][N],trace[N][N], ans = -INF, node, par[N];
vector<int>edge[N];
void dfs(int u, int pre)
{
    dp[u][1] = c[u];
    for(int v : edge[u])if(v != pre)
    {
        par[v] = u;
        dfs(v,u);
        FD(i,p,1)
            FOR(j,1,p - i)
                if(maximize(dp[u][j + i], dp[u][i] + dp[v][j]))
                    trace[v][j + i] = j;
        if(maximize(ans, dp[u][p]))node = u;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)
    {
        cin >> n >> p;
        FOR(i,1,n)
            cin >> c[i];
        FOR(i,1,n-1){
            register int x, y;
            cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        }
        memset(dp,-0x3f,sizeof dp);
        dfs(1,1);
        FOR(i, 1, n) reverse(all(edge[i]));
        queue<ii>qu;
        qu.push(ii(node,p));
        while(!qu.empty())
        {
            ii x = qu.front();
            qu.pop();
            cout << x.fi <<  " ";
            for(int v : edge[x.fi])if(v != par[x.fi])
                if(trace[v][x.se] > 0)
                {
                    qu.push(ii(v, trace[v][x.se]));
                     x.se -= trace[v][x.se];
                }
        }
    }

}

