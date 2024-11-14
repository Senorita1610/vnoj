#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5, maxL = 20;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int n, m, visited[maxN], d[maxN];
vector<ii> edge[maxN];
iii rmq[maxN][maxL];


void dfs(int u, int p, int c){
	visited[u] = 1;
	d[u] = d[p]+1;
	rmq[u][0] = {p,{c,c}};
	for (int i = 1; i < maxL; i++){
		auto x = rmq[u][i-1];
		auto y = rmq[x.first][i-1];
		rmq[u][i] = {
			y.first,
			{min(x.second.first,y.second.first),
			max(x.second.second,y.second.second)}
		};
	}
	for (auto it: edge[u]){
		int v = it.first, w = it.second;
		if (v==p) continue;
		if (visited[v]) continue;
		dfs(v,u,w);
	}
}
iii lca(int u, int v){
	if (d[u]>d[v]) swap(u,v);
	int resmax = -1e9, resmin = 1e9;
	for (int i = maxL-1; i >= 0; i--){
		if (d[rmq[v][i].first]<d[u]) continue;
		resmax = max(resmax,rmq[v][i].second.second);
		resmin = min(resmin,rmq[v][i].second.first);
		v = rmq[v][i].first;
	}
	for (int i = maxL-1; i >= 0; i--){
		if (rmq[u][i].first==rmq[v][i].first) continue;
		auto x = rmq[u][i].second, y = rmq[v][i].second;
		resmax = max({resmax,x.second,y.second});
		resmin = min({resmin,x.first,y.second});
		u = rmq[u][i].first;
		v = rmq[v][i].first;
	}
	if (u!=v){
		int i = 0;
		auto x = rmq[u][i].second, y = rmq[v][i].second;
		resmax = max({resmax,x.second,y.second});
		resmin = min({resmin,x.first,y.second});
		u = rmq[u][i].first;
		v = rmq[v][i].first;
	}
	if (u!=v){
		return {0,{-1e9,-1e9}};
	}
	return {u,{resmin,resmax}};
}

int cha[maxN];
void rs(){
	for (int i = 1; i <= n; i++) cha[i] = i;
}
int timcha(int x){
	return x==cha[x]?x:cha[x]=timcha(cha[x]);
}
bool hop(int u, int v){
	u = timcha(u), v = timcha(v);
	if (u==v) return false;
	cha[v] = u;
	return true;
}

void solve(){
	cin >> n >> m;
	rs();
	vector<iii> edgelist;
	for (int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edgelist.push_back({w,{u,v}});
	}
	sort(edgelist.begin(),edgelist.end());
	reverse(edgelist.begin(),edgelist.end());
	vector<iii> outlist;
	for (auto it: edgelist){
		int u = it.second.first, v = it.second.second, w = it.first;
		if (hop(u,v)){
			edge[u].push_back({v,w});
			edge[v].push_back({u,w});
		} else {
			outlist.push_back(it);
		}
	}
	for (int i = 1; i <= n; i++) if (!visited[i]){
		dfs(i,0,0);
	}
	int res = 0;
	for (auto it: outlist){
		int u = it.second.first, v = it.second.second, w = it.first;
		auto tmp = lca(u,v);
		int mmax = tmp.second.second, mmin = tmp.second.first, z = tmp.first;
		res = max(res,max(mmax,w)+min(mmin,w));
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}

