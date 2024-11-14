#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=200005;
const int inf=0x3f3f3f3f;
int n,m,k;
int dis[N][2],vis[N][2];
int b[M<<1],w[M<<1],nt[M<<1],p[N];
int num;
int c[N];
inline void add(int u,int v,int c){
    num++;
    b[num]=v,w[num]=c,nt[num]=p[u];p[u]=num;
}
struct node{
    int u,pp,dis;
    node(int _u,int _p,int _dis){u=_u,pp=_p,dis=_dis;}
    bool operator<(const node& t)const{
        return dis>t.dis;
    }
};
inline void spfa(int s){
    priority_queue<node> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s][0]=0;
    q.push(node(s,0,0));
    while(!q.empty()){
        int u=q.top().u,pp=q.top().pp;q.pop();
        if(vis[u][pp]) continue;
        vis[u][pp]=1;
        for(int h=p[u];h;h=nt[h]){
            int v=b[h];
            if(pp==0){
                if(dis[v][0]>dis[u][0]+w[h]){
                    dis[v][0]=dis[u][0]+w[h];
                    q.push(node(v,0,dis[v][0]));
                }
                if(c[v]){
                	if(dis[v][1]>dis[u][0]+w[h]-c[v]){
                		dis[v][1]=dis[u][0]+w[h]-c[v];
                		q.push(node(v,1,dis[v][1]));
                    }
                }
            }else {
                if(dis[v][1]>dis[u][1]+w[h]){
                		dis[v][1]=dis[u][1]+w[h];
                		q.push(node(v,1,dis[v][1]));
                }
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    int a,b,t;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&t);
        add(a,b,t);
        add(b,a,t);
    }
    for(int i=1;i<=k;i++){
        scanf("%d%d",&a,&b);
        c[a]=max(c[a],b);
    }
    spfa(n);
    
    for(int i=1;i<n;i++)
        if(dis[i][0]>=dis[i][1]) puts("1");
        else puts("0");
    return 0;
}

