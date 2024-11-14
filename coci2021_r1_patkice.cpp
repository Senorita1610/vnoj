#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 100;
int n, m, si, sj;
string g[mxN];
int best = -1;
char ans;
 
void solve(char c, int i, int j) {
	int d = 0;
	while(1) {
		assert(0 <= i && i < n && 0 <= j && j < m);
		if (g[i][j] == 'x') {
			if (best == -1 || d < best) {
				best = d;
				ans = c;
			}
			return;
		}
		if (g[i][j] == '.' || g[i][j] == 'o') return;
		if (g[i][j] == '>') ++j;
		else if (g[i][j] == '<') --j;
		else if (g[i][j] == '^') --i;
		else if (g[i][j] == 'v') ++i;
		else assert(0);
		++d;
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> g[i];
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == 'o') {
				si = i, sj = j;
			}
		}
	}
	if (sj + 1 < m) solve('E', si, sj + 1);
	if (1 <= si) solve('N', si - 1, sj);
	if (si + 1 < n) solve('S', si + 1, sj);
	if (1 <= sj) solve('W', si, sj - 1);
	if (best != -1) {
		cout << ":)\n" << ans;
	}
	else {
		cout << ":(";
	}
	return 0;
}

