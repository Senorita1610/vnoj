#include <bits/stdc++.h>
#define ar array
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
std::vector<int> find_reachable(std::vector<int> r, std::vector<int> u, std::vector<int> v, std::vector<int> c) {
	int n = sz(r), m = sz(u);
	vector<vector<ar<int, 2>>> adj(n);
	for (int i = 0; i < m; i++) {
		adj[u[i]].push_back({v[i], c[i]});
		adj[v[i]].push_back({u[i], c[i]});
	}
	vector<vector<int>> groups(n);
	for (int i = 0; i < n; i++) groups[i].emplace_back(i);
	vector<int> col(n);
	int timer = 0;
	int mn = 1e9;
	vector<int> ans(n, 1e9);
	int iter = 0;
	while (1) {
		assert(++iter <= 100);
		const int N = sz(groups);
		vector<int> who(n);
		for (int i = 0; i < N; i++) for (int x : groups[i]) who[x] = i;
		vector<vector<int>> adj2(N);
		for (int i = 0; i < N; i++) {
			timer++;
			for (int g : groups[i]) col[r[g]] = timer;
			for (int g : groups[i]) {
				for (auto [u, w] : adj[g]) {
					if (col[w] == timer && i != who[u]) {
						adj2[i].emplace_back(who[u]);
					}
				}
			}
		}
		bool F = 0;
		for (int i = 0; i < N; i++) if (groups[i].size()) {
			if (adj2[i].empty()) {
				if (sz(groups[i]) <= mn) {
					mn = sz(groups[i]);
					for (int g : groups[i]) ans[g] = mn;
				}
				F = 1;
			}
		}
		if (F) { 
			for (int& x : ans) x = x == mn;
			return ans;
		}
		vector<int> tin(N), low(N), stk;
		vector<bool> vis(N);
		vector<vector<int>> groups2;
		int timer2 = 0, comp = 0;
		auto dfs = [&](auto&& s, int v) -> void {
			tin[v] = low[v] = ++timer2;
			stk.emplace_back(v);
			for (int u : adj2[v]) if (!vis[u]) {
				if (!tin[u]) {
					s(s, u), ckmin(low[v], low[u]);
				}
				else ckmin(low[v], tin[u]);
			}
			if (tin[v] == low[v]) {
				groups2.push_back({});
				for (int x = -1; x != v; ) {
					x = stk.back(); stk.pop_back();
					vis[x] = 1;
					if (sz(groups2.back()) < sz(groups[x])) swap(groups[x], groups2.back());
					for (int z : groups[x]) groups2.back().emplace_back(z);
				}
				comp++;
			}
		};
		for (int i = 0; i < N; i++) if (!tin[i]) dfs(dfs, i);
		swap(groups, groups2);
		if (sz(groups) == sz(groups2)) break;
	}
	for (int& x : ans) x = x == mn;
	return ans;
}

