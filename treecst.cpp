#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=300010;
typedef pair<int,int>pii;
struct edge{
	int v;
	edge* next;
}ES[maxn*2],*tot[maxn];
int EC,n,dis[maxn],fa[maxn];
inline void add(int u,int v){
	ES[++EC].v=v;
	ES[EC].next=tot[u];
	tot[u]=ES+EC;
}
inline void BFS(int st){
	static bool visit[maxn];
	static int Q[maxn];
	memset(visit,0,sizeof visit);
	int h=0,t=1;
	Q[1]=st;dis[st]=0;fa[st]=0;
	while(h<t){
		int x=Q[++h];visit[x]=true;
		for(edge* e=tot[x];e;e=e->next){
			if(!visit[e->v]){
				dis[e->v]=dis[x]+1;
				fa[e->v]=x;
				Q[++t]=e->v;
			}
		}
	}
}
struct arr{
	int len,u,v;
	arr(int len=0,int u=0,int v=0): len(len),u(u),v(v){
	}
};
bool operator>(const arr& lhs,const arr& rhs){
	return lhs.len>rhs.len;
}
struct DP{
	int father[maxn],dis[maxn];
	arr g[maxn];
	pii f[maxn];
	void dfs(int x,int fa){
		g[x]=arr(0,x,x);
		f[x]=pii(0,x);
		father[x]=fa;
		dis[x]=dis[fa]+1;
		for(edge* e=tot[x];e;e=e->next){
			if(e->v!=fa){
				dfs(e->v,x);
				if(f[e->v].first+1>f[x].first) f[x]=pii(f[e->v].first+1,f[e->v].second);
				if(g[e->v]>g[x]) g[x]=g[e->v];
			}
		}
		pii tmp=pii(-1,x);
		for(edge *e=tot[x];e;e=e->next){
			if(e->v!=fa&&f[e->v].second!=f[x].second){
				tmp=max(tmp,f[e->v]);
			}
		}
		if(f[x].first+tmp.first+1>g[x].len){
			g[x]=arr(f[x].first+tmp.first+1,f[x].second,tmp.second);
		}
	}
	int getroot(int x){
		int len=g[x].len,u=g[x].u,v=g[x].v;
		if(dis[u]<dis[v]) swap(u,v);
		len=(len+1)/2;
		for(int i=0;i<len;i++) u=father[u];
		return u;
	}
}S,T;
int ans,K;
void solve(int x,int st){
	if(x==st) return;
	int ret=max(T.g[fa[x]].len,S.g[x].len);
	ret=max(ret,(T.g[fa[x]].len+1)/2+1+(S.g[x].len+1)/2);
	if(ret<ans){
		ans=ret;
		K=x;
	}
	solve(fa[x],st);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	BFS(1);
	int st=1;
	for(int i=2;i<=n;i++){
		if(dis[i]>dis[st]) st=i;
	}
	BFS(st);
	int ed=st;
	for(int i=2;i<=n;i++){
		if(dis[i]>dis[ed]) ed=i;
	}
	S.dfs(st,0);
	T.dfs(ed,0);
	ans=dis[ed]+1;
	solve(ed,st);
	printf("%d\n",ans);
	printf("%d %d\n",K,fa[K]);
	printf("%d %d\n",S.getroot(K),T.getroot(fa[K]));
}

