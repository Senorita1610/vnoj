#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pr;

int n,m;
struct edge{
	int v;
	ll w;
	edge(){} edge(int v_,ll w_){ v=v_,w=w_; }
};
vector<edge> e[100005];

ll d[100005];
int fa[100005][30],dep[100005];

priority_queue<pr> q;
void dijkstra(){
	while(!q.empty()){ q.pop(); }
	for(int i=1;i<=n;i++){ d[i]=-1; }
	d[1]=0;q.push(make_pair(0,1));
	while(!q.empty()){
		pr nw=q.top();q.pop();
		int u=nw.second;
		for(int i=e[u].size()-1;i>=0;i--){
			int v=e[u][i].v;
			ll w=e[u][i].w;
			if(d[v]==-1 || d[v]>d[u]+w){
				d[v]=d[u]+w;
				fa[v][0]=u;
				dep[v]=dep[u]+1;
				q.push(make_pair(-d[v],v));
			}
		}
	}
}

void init(){
	for(int j=1;j<=25;j++){
		for(int i=1;i<=n;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
}
int lca(int u,int v){
	if(dep[v]>dep[u]){
		swap(u,v);
	}
	for(int i=25;i>=0;i--) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	for(int i=25;i>=0;i--) if(fa[u][i]!=fa[v][i]){ u=fa[u][i];v=fa[v][i]; }
	return fa[u][0];
}

struct nont{
	int u,v;
	ll w;
	nont(){} nont(int u_,int v_,ll w_){ u=u_,v=v_,w=w_; }
};
bool operator<(nont a,nont b){
	return d[a.u]+d[a.v]+a.w < d[b.u]+d[b.v]+b.w;
}

nont nt[200005];int tp=0;

ll ans[100005];

int nx[100005];
int getfa(int u){
	return (u==nx[u])?u:(nx[u]=getfa(nx[u]));
}

int main(){

	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;ll t;
		scanf("%d%d%lld",&a,&b,&t);
		e[a].push_back(edge(b,t));
		e[b].push_back(edge(a,t));
	}

	dijkstra();
	init();

	for(int i=1;i<=n;i++){
		ans[i]=-1;	
		nx[i]=i;
		for(int j=e[i].size()-1;j>=0;j--){
			int u=i,v=e[i][j].v;
			ll w=e[i][j].w;
			if(fa[v][0]!=u && fa[u][0]!=v && u<v){
				nt[++tp]=nont(u,v,w);
			}
		}
	}
	sort(nt+1,nt+tp+1);

	for(int i=1;i<=tp;i++){
		int x=nt[i].u,y=nt[i].v;
		ll kw=d[x]+d[y]+nt[i].w;
		int u=getfa(x),v=getfa(y);
		while(u!=v){
			if(dep[u]<dep[v]){
				swap(u,v);
			}
			ans[u]=kw-d[u];
			nx[u]=fa[u][0];
			u=getfa(u);
		}
	}

	for(int i=2;i<=n;i++){
		printf("%lld\n",ans[i]);
	}

	return 0;

}

