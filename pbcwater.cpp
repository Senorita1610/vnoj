#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int N=105;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int m,n;
int h[N][N];
int a[N][N];
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
vector<int> w;
void filll(int val)
{
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            h[i][j]=(a[i][j]>=val) ? 1:0;
}
bool ok(int i,int j)
{
    return i>0 && j>0 && i<=m && j<=n;
}
int bfs(int val)
{
    filll(val);
    deque<ii> q;
    for (int i=1;i<=m;i++)
    {
        if (h[i][1]==0) q.pb(mp(i,1));
        if (h[i][n]==0) q.pb(mp(i,n));
        h[i][1]=h[i][n]=1;
    }
    for (int i=1;i<=n;i++)
    {
        if (h[1][i]==0) q.pb(mp(1,i));
        if (h[m][i]==0) q.pb(mp(m,i));
        h[1][i]=h[m][i]=1;
    }
    while (q.size())
    {
        ii t=q.back();
        int i=t.X;
        int j=t.Y;
        q.pop_back();
        for (int k=0;k<4;k++)
        {
            int u=i+x[k];
            int v=j+y[k];
            if (h[u][v]==0 && ok(u,v)) q.push_front(mp(u,v));
            h[u][v]=1;
        }
    }
    int res=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            res+=1-h[i][j];
    return res;
}
int main()
{
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            w.pb(a[i][j]);
        }
    sort(w.begin(),w.end());
    int pre=0;
    int res=0;
    for (int i:w)
    {
        if (i==pre) continue;
        res+=(i-pre)*bfs(i);
        pre=i;
    }
    cout<<res;

}

