#include <bits/stdc++.h>
using namespace std;
#define sp " "
#define endl "\n";
#define fastio() cin.tie(0), ios_base::sync_with_stdio(0)
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define N 200005
 
const int modulo = 1e9 + 7;
 
int dist[N], ans[N], done[N];
vector<int> adj[N];
 
 
int32_t main()
{
	fastio();
 
 
	int n, m, q, k;
	cin>>n>>m>>q>>k;
 
	int cnt = n;
	for (int i = 1; i <= q; i++){
		int node;
		cin>>node;
		done[node] = 1;
		cnt--;
	}
 
	for (int i = 1; i <= m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
 
 
	int step = 1;
	while(cnt > 0){
		queue<int> qu;
		for (int i = 1; i <= n; i++){
			if (done[i]) dist[i] = 0, qu.push(i);
		}
 
		while(!qu.empty()){
			int top = qu.front();
			qu.pop();
			if (dist[top] >= k * step) break;
			for (auto i : adj[top]){
				if (done[i]) continue;
				done[i] = 1;
				qu.push(i);
				dist[i] = dist[top] + 1;
				ans[i] = step;
				cnt--;
			}
		}
		step++;
	}
 
	for (int i = 1; i <= n; i++){
		cout<<ans[i]<<sp;
	}
	cout<<endl;
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " seconds\n";
}

