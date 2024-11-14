#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,cnt,res;
vector<vector<int>>adj(N+5);
vector<int>v;
bool vis[N+5];
void dfs(int u) {
	vis[u]=true;
	cnt++;
	for (auto v:adj[u]) {
		if (!vis[v]) dfs(v);
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
    	if (!vis[i]) {
    		dfs(i);
    		if (i!=1) v.push_back(cnt);
    		else res=cnt;
    		cnt=0;
    	}
    }
    sort(v.rbegin(),v.rend());
    if (!v.empty()) res+=v[0];
    cout<<res;
}

