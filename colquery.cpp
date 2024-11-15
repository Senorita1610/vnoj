#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int par[N+5];
map<int,int>col[N+5];
int find_root(int u) {
    if (par[u]<0) return u;
    return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
    if ((u=find_root(u))==(v=find_root(v))) return;
    if (par[u]>par[v]) swap(u,v);
    for (auto p:col[v]) col[u][p.first]+=p.second;
    col[v].clear();
    par[u]+=par[v];
    par[v]=u;
}
int n,q;
int a[N+5];
int type,u,v,c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        col[i][a[i]]++;
    }
    while(q--) {
        cin>>type;
        if (type==1) {
            cin>>u>>v;
            Union(u,v);
        } else {
            cin>>u>>c;
            u=find_root(u);
            cout<<col[u][c]<<'\n';
        }
    }
}

