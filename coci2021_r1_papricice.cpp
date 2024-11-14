#include <bits/stdc++.h>
#define fast cin.tie(0)->sync_with_stdio(0);
#define int long long
#define inf ((int)1e18)
#define N 200005
using namespace std;
vector <vector <int> > adj(N);
set <int> subt;
deque <int> dq;
int under[N];
int n, ans = inf;
 
void dfs0(int node, int ata) {
	under[node] = 1;
	for(auto it:adj[node]) {
		if(it == ata) continue;
		dfs0(it, node);
		under[node] += under[it];
	}
}
 
void dfs(int node, int ata) {
	int a = under[node];
	dq.push_front(a);
	// ----------------------------------------
	auto index = subt.lower_bound((n - a) / 2); // >= ilk eleman
	if(index == subt.end() and subt.size()) index--;
	// cout << node << ":\n";
	// for(auto it:dq) {
	// 	cout << it << " ";
	// }
	// cout << "\n";
	if(subt.size()) {
		int b = *(index);
		int c = n - b - a;
		int tans = max(abs(a - b), max(abs(a - c), abs(c - b)));
		ans = min(ans, tans);
		// cout << a << " " << b << " " << c << "\n";
		if(index != subt.end() and index != subt.begin()) {
			index--;
			int b = *(index);
			int c = n - b - a;
			int tans = max(abs(a - b), max(abs(a - c), abs(c - b)));
			ans = min(ans, tans);
			// cout << a << " " << b << " " << c << "\n";
		}
	}
	// ----------------------------------------
	{
		auto ind = lower_bound(dq.begin(), dq.end(), (n + a) / 2);
		if(ind == dq.end()) ind--;
		int b = *(ind) - a;
		int c = n - b - a;
		int tans = max(abs(a - b), max(abs(a - c), abs(c - b)));
		ans = min(ans, tans);
		if(ind != dq.begin()) {
			ind--;
			int b = *(ind) - a;
			int c = n - b - a;
			int tans = max(abs(a - b), max(abs(a - c), abs(c - b)));
			ans = min(ans, tans);
		}
	}
	// ----------------------------------------
	for(auto it:adj[node]) {
		if(it == ata) continue;
		dfs(it, node);
	}
	subt.insert(under[node]);
	dq.pop_front();
}
 
int32_t main(){
	fast
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs0(1, 0);
	dfs(1, 0);
	cout << ans << "\n";
}

