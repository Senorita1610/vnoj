#include<bits/stdc++.h>
using namespace std;
const int N=4e3,M=4e5;
int n,m,q;
vector<vector<pair<int,long long>>>adj(N+5);
struct edge{
	int u,v;
	long long w;
	bool operator < (const edge &other) const {
		return w<other.w;
	}
} e[M+5];
int par[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
	if (par[v]<par[u]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
long long sum;
long long mx[N+5][N+5];
void dfs(int root,int u,int par) {
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		mx[root][v]=max(mx[root][u],w);
		dfs(root,v,u);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(par,-1,sizeof(par));
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m);
	for (int i=1;i<=m;i++) {
		int u=find_root(e[i].u),v=find_root(e[i].v);
		if (u==v) continue;
		sum+=e[i].w;
		adj[e[i].u].push_back({e[i].v,e[i].w});
		adj[e[i].v].push_back({e[i].u,e[i].w});
		Union(u,v);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			mx[i][j]=LLONG_MIN;
	for (int i=1;i<=n;i++) dfs(i,i,0);
	cin>>q;
	while (q--) {
		int a,b;
		cin>>a>>b;
		cout<<sum-mx[a][b]<<'\n';
	}
}

