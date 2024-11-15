#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int I = 1e9+7;
struct pack {
	int u, l, t;
	bool operator < (const pack& p) const {
		return l > p.l;
	}

	static pack mkpack(int u, int l, int t) {
		pack p;
		p.u = u; p.l = l; p.t = t;
		return p;
	}
};

int calc(int k, int n, vector<vector<pack>>& adj) {
	priority_queue<pack> q;
	q.push(pack::mkpack(0, 0, 0));
	vector<vector<int>> d(k+1, vector<int>(n, I));
	while (q.size()) {
		pack u = q.top(); q.pop();
		for (pack& v: adj[u.u]) {
			int des = v.u,
				len = u.l + v.l,
				cos = u.t + v.t;
			if (cos > k) continue;
			if (len < d[cos][des]) {
				d[cos][des] = len;
				q.push(pack::mkpack(des, len, cos));
			}
		}
	}
	//
	int res = d[0][n-1];
	for (int i = 1; i <= k; i++) res = min(res, d[i][n-1]);
	if (res == I) return -1;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int k, n, r, u, v, l, t;
		cin >> k >> n >> r;
		vector<vector<pack>> adj(n);
		while (r--) {
			cin >> u >> v >> l >> t;
			u--; v--;
			adj[u].push_back(pack::mkpack(v, l, t));
		}
		cout << calc(k, n, adj) << "\n";
	}
	return 0;
}

