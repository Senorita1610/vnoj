#include <bits/stdc++.h>
using namespace std;
 
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define s second
#define f first
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll LOGN = 21;
const ll MAXN = 2e4 + 100;
 
vector<vector<int>> here;
vector<int> A, DW, EL;
 
int main() {
	fast
	int n;
	cin >> n;
 
	here = vector<vector<int>>(n+1, vector<int>());
	A = vector<int>(n+1);
	DW = vector<int>(n+1);
	EL = vector<int>(n+1);
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	for (int i = 1; i <= n; i++)
		cin >> DW[i];
	for (int i = 1; i <= n; i++) {
		cin >> EL[i];
		here[A[i]].push_back(EL[i]);
	}
 
	pair<int,int> opt = {1e8, 0};
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += here[i].size();
		opt = min(opt, {cnt - i, i});
	}
 
	int first_plc = opt.s + 1;
	if (first_plc == n + 1)
		first_plc = 1;
 
	multiset<int> st;
	cnt = 0;
	for (int i = first_plc; i <= n; i++) {
		for (auto u : here[i])
			st.insert(u);
		auto it = st.lower_bound(DW[i]);
		if (it == st.end())
			st.erase(st.begin());
		else {
			cnt++;
			st.erase(it);
		}
	}
	for (int i = 1; i < first_plc; i++) {
		for (auto u : here[i])
			st.insert(u);
		auto it = st.lower_bound(DW[i]);
		if (it == st.end())
			st.erase(st.begin());
		else {
			cnt++;
			st.erase(it);
		}
	}
 
	cout << cnt << "\n";
}

