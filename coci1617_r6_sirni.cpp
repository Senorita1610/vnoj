#include <bits/stdc++.h>
 
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int maxn=1e5+7;
int n;
int r[maxn];
int sz[maxn];
vector<int>dd;
vector<int>p;
vector<vector<ii>>ed;
int Find(int u)
{
    return (u==r[u])?u:r[u]=Find(r[u]);
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    p.resize(n);
    for(int &c:p){
        cin>>c;
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    int maxx=p.back();
    n=p.size();
    dd.resize(maxx+7);
    for(int i=0;i<maxx;i++)dd[i]=-1;
    for(int i=0;i<n;i++){
        dd[p[i]]=i;
    }
    for(int i=maxx-1;i>=0;i--){
        if(dd[i]==-1)dd[i]=dd[i+1];
    }
    ed.resize(p[0]+1);
    for(int i=n-2;i>=0;i--){
        if(p[i+1]%p[i]<=p[0])ed[p[i+1]%p[i]].push_back({i,i+1});
        for(int j=2*p[i];j<=maxx;j+=p[i]){
            if(p[dd[j]]%p[i]<=p[0])ed[p[dd[j]]%p[i]].push_back({i,dd[j]});
        }
    }
    for(int i=0;i<n;i++){
        r[i]=i;
        sz[i]=1;
    }
    long long res=0;
    for(int i=0;i<p[0];i++){
        for(ii p:ed[i]){
            int u=Find(p.fi);
            int v=Find(p.se);
            if(u!=v){
                if(sz[u]<sz[v])swap(u,v);
                r[v]=u;
                sz[u]+=sz[v];
                res+=i;
                if(sz[u]==n){
                    cout<<res;
                    return 0;
                }
            }
        }
    }
    cout<<res;
    return 0;
}

