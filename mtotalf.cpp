#include<bits/stdc++.h>
#define rg register int 
using namespace std;
int N,cnt=1,head[4101],dep[4100];
int ans,flo;
struct node{
    int nxt;
    int to;
    int w;
}edge[11200];
void add_edge(int u,int v,int w)
{
    edge[++cnt].nxt=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt;
}
bool bfs()
{
    memset(dep,0,sizeof dep);
    queue< int >x;x.push(1);
    dep[1]=1;
    while(!x.empty())
    {
        int u=x.front();x.pop();
        for(rg i=head[u];i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(!dep[v]&&edge[i].w)
            {
                dep[v]=dep[u]+1;
                if(v==26) return 1;
                x.push(v);
            }
        }
    }
    return 0;
}
int cur[4010];
int dinic(int u,int flow)
{
    if(u==26 || flow == 0) return flow;
    int k;int res=0;
    for(rg i=cur[u];i;i=edge[i].nxt)
    {
        cur[u] = i;
        int v=edge[i].to;
        if(dep[v]==dep[u]+1&&edge[i].w)
        {
            k=dinic(v,min(edge[i].w,flow));
            if(!k) continue;
            edge[i].w-=k;
            edge[i^1].w+=k;
            res+=k;flow -=k;
            if(flow == 0) break;
        }
    }
    return res;
}
signed main()
{
    scanf("%d",&N);
    while(N--)
    {
        char a,b;int w;
        cin>>a>>b>>w;
        add_edge(int(a-'A'+1),int(b-'A'+1),w);
        add_edge(int(b-'A'+1),int(a-'A'+1),0);
    }
    while(bfs())
    {
        memcpy(cur,head,sizeof(cur));
        int maxflow = dinic(1,19260817);
        ans += maxflow;
    }
    printf("%d\n",ans);
    return 0;
}

