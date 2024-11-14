#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
using namespace std;
#pragma GCC optimize("Ofast")
#define REP(i, a, b) \
	for (int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
	for (msi::iterator it = (c).begin(); it != (c).end(); it++)

using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
const ll INF = 1e18;
const int N = 5005;
int n, k;
array<int, 2> a[N];
int opt[N][N];
ll f[N][N], dp[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1];
	}
	sort(a + 1, a + 1 + n);
	if (k >= n) {
		cout << 0 << '\n';
		return 0;
	}
	for (int l = 1; l <= n; ++l) {
		int ptr = l;
		ll sumL = 0, sumR = 0, cntL = 0, cntR = 0;
		for (int r = l; r <= n; ++r) {
			sumR += 1ll * a[r][0] * a[r][1];
			cntR += a[r][1];
			while (cntR >= cntL) {
				sumR -= 1ll * a[ptr][0] * a[ptr][1];
				cntR -= a[ptr][1];
				sumL += 1ll * a[ptr][0] * a[ptr][1];
				cntL += a[ptr][1];
				++ptr;
			}
			f[l][r] = (sumR - 1ll * a[ptr - 1][0] * cntR) + (1ll * a[ptr - 1][0] * cntL - sumL);
		}
	}
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; ++i) {
		dp[1][i] = f[1][i];
		opt[1][i] = 1;
	}
	for (int i = 2; i <= k; ++i) {
		opt[i][n + 1] = n;

		for (int j = n; j >= i; --j) {
			dp[i][j] = INF;
			for (int split = opt[i - 1][j]; split <= opt[i][j + 1]; ++split) {
				if (dp[i][j] > dp[i - 1][split - 1] + f[split][j]) {
					dp[i][j] = dp[i - 1][split - 1] + f[split][j];
					opt[i][j] = split;
				}
			}
		}
	}
	cout << dp[k][n] << '\n';
	return 0;
}

