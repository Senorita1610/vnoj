#include<bits/stdc++.h>
using namespace std;
const int N=1e4,LG=__lg(N);
int n,m;
vector<vector<pair<int,int>>>adj(N+1);
int up[N+1][LG+1],c[N+1][LG+1],h[N+1];
void dfs(int u) {
	for (auto [v,k]:adj[u]) {
		if (v==up[u][0]) continue;
		h[v]=h[u]+1;
		up[v][0]=u;
		c[v][0]=(k==2);
		for (int i=1;i<=LG;i++) {
			up[v][i]=up[up[v][i-1]][i-1];
			c[v][i]=(c[v][i-1]|c[up[v][i-1]][i-1]);
		}
		dfs(v);
	}
}
int lca(int u,int v) {
	int res=0;
	if (h[u]!=h[v]) {
		if (h[u]<h[v]) swap(u,v);
		int k=h[u]-h[v];
		for (int i=0;(1<<i)<=k;i++) {
			if (k>>i&1) {
				res|=c[u][i];
				u=up[u][i];
			}
		}
	}
	if (u==v) return res;
	int k=__lg(h[u]);
	for (int i=k;i>=0;i--) {
		if (up[u][i]!=up[v][i]) {
			res|=c[u][i];
			res|=c[v][i];
			u=up[u][i];
			v=up[v][i];
		}
	}
	res|=(c[u][0]|c[v][0]);
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=2;i<=n;i++) {
    	int x,k;
    	cin>>x>>k;
    	adj[i].push_back({x,k});
    	adj[x].push_back({i,k});
    }
    dfs(1);
    while (m--) {
    	int u,v;
    	cin>>u>>v;
    	if (lca(u,v)) cout<<"YES"<<'\n';
    	else cout<<"NO"<<'\n';
    }
}

