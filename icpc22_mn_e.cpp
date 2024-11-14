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
#define INF 2000000000
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;


const int N = 5e5 + 5;

int n;
ll a[N], b[N], a2[N], b2[N], ab[N];

double find_min_x(int l, int r) {
	double x = ab[r] - ab[l - 1];
	double y = b2[r] - b2[l - 1];
	return x / y;
}

double calc(double x, int l, int r) {
	return x * x * (b2[r] - b2[l - 1]) - x * 2 * (ab[r] - ab[l - 1]) + (a2[r] - a2[l - 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		a2[i] = a2[i - 1] + a[i] * a[i];
		b2[i] = b2[i - 1] + b[i] * b[i];
		ab[i] = ab[i - 1] + a[i] * b[i];
	}

	double ans = 0;
	vector<tuple<int, double, double>> A;
	for (int i = 1; i <= n; ++i) {
		int l = i;
		double x = find_min_x(l, i);
		double cost = calc(x, l, i);

		while (!A.empty() && x >= get<1>(A.back())) {
			l = get<0>(A.back());
			ans -= get<2>(A.back());
			A.pop_back();

			x = find_min_x(l, i);
			cost = calc(x, l, i);
		}

		ans += cost;
		A.emplace_back(l, x, cost);
	}

	cout << fixed << setprecision(15) << ans << '\n';
	return 0;
}

