#include<bits/stdc++.h>
using namespace std;
const int N=2e4;
int n,m;
vector<int>adj[N+5];
int sz[N+5],low[N+5],num[N+5],tim;
bool vis[N+5];
long long res;
void pre_dfs(int u,int par) {
	num[u]=low[u]=++tim;
	sz[u]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (!num[v]) {
			pre_dfs(v,u);
			low[u]=min(low[u],low[v]);
			sz[u]+=sz[v];
		} else low[u]=min(low[u],num[v]);
	}
}
void dfs(int u,int par,int root) {
	vis[u]=true;
	long long sum=sz[root]-1;
	vector<long long>cur;
	for (auto v:adj[u]) {
		if (v==par||vis[v]) continue;
		dfs(v,u,root);
		if (u==root||low[v]>=num[u]) {
			cur.push_back(sz[v]);
			sum-=sz[v];
		}
	}
	cur.push_back(sum);
	sum=cur[0];
	for (int i=1;i<(int)cur.size();i++) {
		res+=cur[i]*sum;
		sum+=cur[i];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
    	if (!num[i]) pre_dfs(i,-1);
    }
    for (int i=1;i<=n;i++) {
    	if (!vis[i]) dfs(i,i,i);
    }
    double ans=(double)res/(double)n;
    cout<<fixed<<ans;
}

