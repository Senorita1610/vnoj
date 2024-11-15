#include <bits/stdc++.h>
using namespace std;

const int N = 26, mod = 1337377;	

int n, f[300010];
struct node {
	node* child[N]; bool end;
	node() { for (int i = 0; i < N; i++) child[i] = NULL; end = 0; }
	~node() { for (int i = 0; i < N; i++) delete child[i]; }
} *Trie = new node();

void add(string s) {
	node* cur = Trie;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (cur -> child[s[i] - 'a'] == NULL) cur -> child[s[i] - 'a'] = new node();
		cur = cur -> child[s[i] - 'a'];
	}
	cur -> end = 1;
}

void solve(string s) {
	f[0] = 1;
	for (int i = 0; i < s.size(); i++) {
		node* cur = Trie;
		for (int j = i; j >= 0; j--) {
			cur = cur -> child[s[j] - 'a'];
			if (cur == NULL) break;
			if (cur -> end) f[i + 1] = (f[i + 1] + f[j]) % mod;
		}
	}
	printf("%d\n", f[s.size()]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s >> n;
	for (int i = 1; i <= n; i++) { string str; cin >> str; add(str); }
	solve(s);
}

