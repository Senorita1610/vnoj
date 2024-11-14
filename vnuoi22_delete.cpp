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
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define fi first
#define se second
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FD(i,l,r) for(int i = l ; i >= r ; i--)
#define REP(i,l,r) for(int i = l ; i <r ; i++)

typedef long long ll ;
typedef pair<int,int> ii;
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b),1 : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b),1 : 0); }

const int N = 5e5 + 5;
const int MOD = 998244353;
//const ll base = 311;
//const int BLOCK = 488;
const ll INF = 1e18 + 7;
int n, m, c1[N], Node[N], nTopo = 0, id[N], k, deg1[N], deg2[N];
bool vis[N];
ll d[N], ans = 1;
ii edge1[N], edge2[N];
vector<ii>adj[N];
vector<int> Dag[N];
void init(void)
{
    cin >> n >> m >> k;
    FOR(i,1,m){
        register int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(ii(v,w));
        adj[v].pb(ii(u,w));
        edge1[i] = ii(u, v);
        c1[i] = w;
    }
    FOR(i,1,k){
        register int u, w;
        cin >> u >> w;
        adj[1].pb(ii(u,w));
        adj[u].pb(ii(1,w));
        edge2[i] = ii(u,w);
    }
}
void add(ll &a, const ll &b)
{
    a += b;
    while(a >= MOD)a -= MOD;
}
ll Pow(int a, int b)
{
    if(b == 0)return 1;
    if(b == 1)return a;
    ll t = Pow(a, b/2);
    if(b&1)return 1LL * (1LL * t * t %MOD) * a %MOD;
    else return (1LL * t * t % MOD);
}
void process(void)
{
    priority_queue<pair<ll, int>>qu;
    FOR(i,1,n)
        d[i] = INF;
    d[1] = 0;
    qu.push({d[1], 1});
    while(!qu.empty())
    {
        pair<ll, int>  x = qu.top();
        qu.pop();
        if(d[x.se] != -x.fi)continue;
        for(ii v : adj[x.se])
            if(minimize(d[v.fi], d[x.se] + v.se))
                qu.push({-d[v.fi], v.fi});
    }
    FOR(j,1,m)
    {
            ii i = edge1[j];
            if(d[i.fi] + c1[j] == d[i.se]){
                deg1[i.se]++;
            }
            if(d[i.se] + c1[j] == d[i.fi]){
                deg1[i.fi]++;
            }
    }
    FOR(j,1,k)
    {
        ii i = edge2[j];
        if(i.se == d[i.fi]){
            deg2[i.fi]++;
        }
        else ans =1LL * ans * 2 % MOD;
    }
    FOR(i,2,n)
        if(deg1[i] > 0)
            ans = 1LL * ans *  Pow(2,deg2[i]) %MOD;
        else
        ans =  1LL * ans *  (Pow(2, deg2[i]) - 1) % MOD;
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    process();
}

