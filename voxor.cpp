#include <bits/stdc++.h>
using namespace std;

const int N = 2, MaxBit = 30;
int n, q, Xor;

struct node {
	node* c[N]; int f, nChild;
	node() { for (int i = 0; i < N; i++) c[i] = NULL; f = nChild = 0; }
	~node() { for (int i = 0; i < N; i++) delete c[i]; }
} *Trie = new node();

void add(int x) {
	node* cur = Trie;
	for (int i = MaxBit - 1; i >= 0; i--) {
		int bit = ((x & (1LL << i)) ? 1 : 0);
		if (cur -> c[bit] == NULL) { cur -> c[bit] = new node(); cur -> nChild++; }
		cur = cur -> c[bit];
		cur -> f++;
	}
}

int find(int k) {
	node* cur = Trie; int ans = 0;
	for (int i = MaxBit - 1; i >= 0; i--) {
		if (!cur -> nChild) break;
		if (cur -> nChild == 1) {
			for (int j = 0; j < N; j++) 
				if (cur -> c[j] != NULL) { cur = cur -> c[j]; ans += (1LL << i) * j; break; }
		}
		else {
			if (Xor & (1LL << i)) {
				if ((cur -> c[1]) -> f >= k) { cur = cur -> c[1]; ans += (1LL << i); }
				else { k -= (cur -> c[1]) -> f; cur = cur -> c[0]; }
			}
			else {
				if ((cur -> c[0]) -> f >= k) { cur = cur -> c[0]; }
				else { k -= (cur -> c[0]) -> f; cur = cur -> c[1]; ans += (1LL << i); }
			}
		}
	}
	return ans ^ Xor;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q; for (int i = 1; i <= n; i++) { int x; cin >> x; add(x); }

	while(q--) {
		string type; cin >> type; 
		if (type == "XOR") { int x; cin >> x; Xor ^= x; }
		else {
			int k; cin >> k; k = n + 1 - k; 
			printf("%d\n", find(k));
		}
	}

}

