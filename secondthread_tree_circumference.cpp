#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
vector<int> edge[300005];

ii dfs(int p, int u){
	ii res = {0,u};
	for (int v: edge[u]) if (v!=p){
		res = max(res,dfs(u,v));
	}
	res.first++;
	return res;
}

int main(){
	int n; cin >> n;
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	ii res = dfs(0,1);
	res = dfs(0,res.second);
	cout << (res.first-1)*3;
	
	return 0;
}

