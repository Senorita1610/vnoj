#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int n,m,d[N],fa[N],x,y,z,res;
struct Edge{
    int id,w;
};
int w[N];
basic_string<Edge>G[N];
void dfs(int u){for(int i=0,v;i<G[u].size();i++)if(!d[v=G[u][i].id])d[v]=d[u]+1,fa[v]=u,w[v]=G[u][i].w,dfs(v);}
int main(){
    cin>>n>>m,d[1]=1;
    for(int i=1;i<n;i++)cin>>x>>y>>z,G[x]+=(Edge){y,z},G[y]+=(Edge){x,z};
    dfs(1);
    for(int i=1;i<=m;i++){
        cin>>x>>y;res=0;
        while(x!=y){
            if(d[x]>d[y])res+=w[x],x=fa[x];
            else res+=w[y],y=fa[y];
        }
        cout<<res<<endl;
    }
    return 0;
}

