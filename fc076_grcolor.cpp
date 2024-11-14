#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,q;
vector<vector<int>>adj(N+5);
bool done[N+5][11];
int col[N+5];
struct query{
	int u,d,c;
} qu[N+5];
void bfs(int u,int d,int c) {
	queue<pair<int,int>>q;
	q.push({u,0});
	if (!col[u]) col[u]=c;
	while (!q.empty()) {
		int u=q.front().first;
		int dist=q.front().second;
		q.pop();
		if (dist==d) continue;
		for (auto v:adj[u]) {
			if (done[v][d-dist-1]) continue;
			if (!col[v]) col[v]=c;
			q.push({v,dist+1});
			done[v][d-dist-1]=true;
		} 
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
	cin>>q;
	for (int i=1;i<=q;i++) cin>>qu[i].u>>qu[i].d>>qu[i].c;
	for (int i=q;i>=1;i--) 
		if (!done[qu[i].u][qu[i].d]) bfs(qu[i].u,qu[i].d,qu[i].c);
	for (int i=1;i<=n;i++) cout<<col[i]<<'\n';
}

