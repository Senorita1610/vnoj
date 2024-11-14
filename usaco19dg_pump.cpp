#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,head[1001],dis[1001],F[1001]; 
double ans; 
bool vis[1001];
struct edge
{
    int nxt,to,w,f;
}e[2001];
struct node
{
    int pos,dis;
    bool operator<(const node &x)const 
    {
        return dis>x.dis;
    }
};
void add(int u,int v,int w,int f) 
{
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    e[cnt].w=w; 
    e[cnt].f=f;
    head[u]=cnt;
}
int dijkstra(int s,int minf)
{
    memset(dis,0x3f,sizeof(dis)); 
    memset(vis,false,sizeof(vis)); 
    dis[s]=0; 
    priority_queue<node>Q;
    Q.push((node){s,0}); 
    while(Q.size())
    {
        int x=Q.top().pos; 
        Q.pop(); 
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head[x];i;i=e[i].nxt) 
        {
            int y=e[i].to;
            if(e[i].f<minf)continue;
            if(dis[y]>dis[x]+e[i].w) 
            {
                dis[y]=dis[x]+e[i].w;
                if(!vis[y])Q.push((node){y,dis[y]});
            }
        }
    }
    return dis[n];
}
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),c=read(),f=read();
        add(u,v,c,f);
        add(v,u,c,f);
        F[i]=f;
    }
    for(int i=1;i<=m;i++)ans=max(ans,1e6*F[i]/dijkstra(1,F[i]));
    printf("%d",int(ans)); 
    return 0;
}

