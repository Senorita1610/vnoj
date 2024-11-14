#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+7, I = 1e9+7;
int a, b, n;
int v[N], dp[N];
int lis() {
	int p = 0;
	dp[0] = -I; dp[n+1] = I;
	for (int i = 0; i < n; i++) {
		int l = 0, r = p;
		while (l < r) {
			int m = (l + r + 1) >> 1;
			if (dp[m] <= v[i]) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		if (l < p) {
			if (v[i] < dp[l+1]) dp[l+1] = v[i];
		} else {
			dp[++p] = v[i];
		}
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	n = b - a + 1;
	for (int i = 0; i < n; i++) v[i] = i+a;
	sort(v, v + n, [](int i, int j){
		return to_string(i) < to_string(j);
	});
	cout << n - lis() << "\n";
	return 0;
}

