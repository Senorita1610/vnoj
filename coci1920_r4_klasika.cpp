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
#define M 30
 
const int modulo = 1e9 + 7;
 
 
int par[N], dist[N], sz[N], ans[N], timee[N];
vector<pii> qry[N];
vector<int> child[N];
 
 
struct Node{
	Node* nxt[2];
	int mini;
	Node(){
		nxt[0] = nxt[1] = NULL;
		mini = modulo;
	}
};
 
Node *trie[N];
 
void add(Node *root, int val, int t){
	for (int i = M; i >= 0; i--){
		int ind = 0;
		if (val & (1<<i)) ind = 1;
		if (root->nxt[ind] == NULL){
			root->nxt[ind] = new Node;
		}
 
		root = root->nxt[ind];
		root->mini = min(root->mini, t);
	}
}	
 
int query(Node *root, int val, int t){
	int ans = 0;
	for (int i = M; i >= 0; i--){
		int ind = 1;
		if (val & (1<<i)) ind = 0;
		if (root->nxt[ind] != NULL && root->nxt[ind]->mini <= t) ans |= (1<<i), root = root->nxt[ind];
		else root = root->nxt[1 ^ ind];
	}
	return ans;
}
 
void merge_subtree(Node *a, Node *b){
	a->mini = min(a->mini, b->mini);
	for (int i = 0; i < 2; i++){
		if (b->nxt[i] == NULL) continue;
		if (a->nxt[i] == NULL)  a->nxt[i] = b->nxt[i];
		else merge_subtree(a->nxt[i], b->nxt[i]);
	}
}
 
void dfs(int node, int root){
	trie[node] = new Node;
	add(trie[node], dist[node], timee[node]);
	sz[node] = 1;
	for (auto i : child[node]){
		dfs(i, node);
		if (sz[i] > sz[node]){
			swap(trie[node], trie[i]);
		}
		merge_subtree(trie[node], trie[i]);
		sz[node] += sz[i];
	}
 
	for (auto i : qry[node]){
		ans[i.nd] = query(trie[node], i.st, i.nd);
	}
}
 
 
int32_t main()
{
	fastio();
	memset(ans, -1, sizeof(ans));
 
	int q;
	cin>>q;
	int cntr = 2;
	for (int i = 1; i <= q; i++){
		string type;
		cin>>type;
		if (type == "Add"){
			int x, y;
			cin>>x>>y;
			par[cntr] = x;
			child[x].pb(cntr);
			dist[cntr] = dist[x] ^ y;
			timee[cntr] = i;
			cntr++;
		}
		else{
			int a, b;
			cin>>a>>b;
			qry[b].pb({dist[a], i});
		}
	}
 
	dfs(1, 0);
 
	for (int i = 1; i <= q; i++){
		if (ans[i] != -1) cout<<ans[i]<<endl;
	}
 
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " seconds\n";
}

