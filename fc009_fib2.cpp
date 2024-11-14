#include<bits/stdc++.h>
using namespace std;
const int N = 9 + 46;
int t, a[N];
void solve() {
	int n, k;
	cin >> n >> k;
	int ans = 0, p = n % 2;
	while (k) {
		int i = 40 - p;
		while (a[i] > k) i -= 2;
		k -= a[i];
		ans += a[i - 2];
		p = 1 - p;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	a[0] = 1;
	for (int i = 2; i <= 45; i++) a[i] = a[i - 1] + a[i - 2];
	cin >> t;
	while(t--)
		solve();
	return 0;
}

