#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int t;

void solve() {
	int a, b;
	cin >> a >> b;
	int res = 0;
	if(a >= 2) res += a * (a - 1) * (a - 2);
	if(b >= 2) res += b * (b - 1) * (b - 2);
	if(a >= 1) res += b * a * (a - 1);
	if(b >= 1) res += a * b * (b - 1);
	cout << res << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	cin >> t;
	while(t--)
		solve();
	return 0;
}

