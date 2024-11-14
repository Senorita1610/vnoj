#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
string s[300005];
int n, m, p[300005];
long long f[300005];

int to[1000005][26], nTrie, nodeLeaf[300005];
long long valTrie[1000005];

vector<int> edge[100005], heavyEdge[100005]; 
bool isHeavy[100005];
int deg[100005];
long long valNode[100005], valPassive[100005];

void buildTrie(){
	for (int i = 0; i < n; i++){
		int u = 0;
		for (char c: s[i]){
			if (to[u][c-'A']==0) to[u][c-'A'] = ++nTrie;
			u = to[u][c-'A'];
		}
		nodeLeaf[i] = u;
	}
}
void updateTrie(int i, long long val){
	int u = 0;
	for (char c: s[i]){
		u = to[u][c-'A'];
		if (u==nodeLeaf[i]) return;
		valTrie[u] = max(valTrie[u],val);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i] >> p[i];
	buildTrie();
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		deg[u]++; deg[v]++;
	}
	int T = sqrt(m);
	for (int i = 1; i <= 1e5; i++) isHeavy[i] = deg[i]>=T;
	for (int i = 1; i <= 1e5; i++) for (int j: edge[i]) if (isHeavy[j]) heavyEdge[i].push_back(j);
	
	long long res = 0;
	for (int i = 0; i < n; i++){
		f[i] = max(valTrie[nodeLeaf[i]],valPassive[p[i]]) + p[i];
		for (int x: heavyEdge[p[i]]) f[i] = max(f[i],valNode[x]+p[i]);
		updateTrie(i,f[i]);
		if (isHeavy[p[i]]) valNode[p[i]] = max(valNode[p[i]],f[i]);
		else for (int x: edge[p[i]]) valPassive[x] = max(valPassive[x],f[i]);
		res = max(res,f[i]);
	}
	cout << res;
	
	return 0;
}

