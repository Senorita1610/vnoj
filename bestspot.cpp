#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<vector<ii>> a;
int d[N],f[N],ck[N],m,n,p;

void dijkstra(int s)
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push(mp(0,s));
    for (int i=1;i<=n;i++)
    {
        ck[i]=0;
        d[i]=MOD;
    }
    d[s]=0;
    while (q.size())
    {
        ii t=q.top();
        q.pop();
        if (d[t.Y]!=t.X)
            continue;
        int s=t.X;
        int u=t.Y;
        ck[u]=1;
        for (ii temp:a[u])
        {
            int v=temp.Y;
            int w=temp.X;
            if (s+w>=d[v]) continue;
            d[v]=s+w;
            q.push(mp(s+w,v));
        }
    }
}
int main()
{
    cin>>n>>p>>m;
    for (int i=1;i<=p;i++)
        cin>>f[i];
    a.resize(n+1);
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        a[u].pb(mp(w,v));
        a[v].pb(mp(w,u));
    }
    int ans=MOD;
    int dans=1;
    for (int i=1;i<=n;i++)
    {
        dijkstra(i);
        int res=0;
        for (int i=1;i<=p;i++)
            res+=d[f[i]];
        if (res>=ans) continue;
        ans=min(res,ans);
        dans=i;
    }
    cout<<dans;
}

