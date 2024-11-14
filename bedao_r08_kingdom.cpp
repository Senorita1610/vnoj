#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
vector<vector<int>>adj(N+5);
int tot,c[N+5];
vector<pair<int,int>>edge;
vector<int>res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edge.push_back({u,v});
	}
	for (int i=1;i<=n;i++) cin>>c[i];
	for (auto [u,v]:edge) tot+=(c[u]!=c[v]);
	for (int u=1;u<=n;u++) {
		int cnt=0;
		for (auto v:adj[u]) cnt+=(c[u]!=c[v]);
		if (cnt==tot) res.push_back(u);
	}
	if (res.empty()) cout<<"NO";
	else {
		cout<<"YES"<<'\n';
		for (auto i:res) cout<<i<<' ';
	}
}

