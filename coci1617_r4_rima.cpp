#include <bits/stdc++.h>
 
#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r
 
using namespace std;
 
const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
 
struct Node {
	int cnt, nxt[26], dp;
	Node() {
		cnt = 0; dp = 0;
		for (int i = 0; i < 26; i++) nxt[i] = -1;
	}
};
 
vector < Node > trie;
 
int n, res = 0;
 
void create() {
	trie.pb(Node());
	return ;
}
 
void add(const string &s) {
	int cur = 0;
	for (auto c : s) {
		if (trie[cur].nxt[c - 'a'] == -1) {
			create();
			trie[cur].nxt[c - 'a'] = SZE(trie) - 1;
		}
		cur = trie[cur].nxt[c - 'a'];
	}
	trie[cur].cnt ++;
}
 
void dfs(int u) {
	int total = 0;
	vector < int > temp;
	for (int i = 0; i < 26; i++) {
		int v = trie[u].nxt[i];
		if (v == -1) continue;
		dfs(v); total += trie[v].cnt;
		temp.pb(trie[v].dp);
	}
	sort(temp.begin(), temp.end(), greater < int >());
	if (trie[u].cnt != 0) {
		trie[u].dp = trie[u].cnt + total;
		if (SZE(temp)) trie[u].dp += temp[0] - 1;
		trie[u].dp = max(trie[u].dp, 1);
	}
	res = max(res, trie[u].dp);
	if (SZE(temp) >= 2) res = max(res, temp[0] + temp[1] + total - 2 + trie[u].cnt);
}
 
int main() {
	fast;
	cin >> n;
	create();
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		reverse(s.begin(), s.end());
		add(s);
	}
	dfs(0);
	cout << res;
}

