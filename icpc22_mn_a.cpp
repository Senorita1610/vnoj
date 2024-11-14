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



int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, win = 0, draw = 0, lose = 0;
	cin >> n;

	for (int x = 0; x <= 29; ++x) {
		for (int y = 0; y <= 29; ++y) {
			ll f = ((n >> x) - (n >> (x + 1))) * ((n >> y) - (n >> (y + 1)));

			if (min(x, y) % 2 == 1) {
				win += f;
			} else if (x == y) {
				lose += f;
			} else {
				draw += f;
			}
		}
	}

	cout << win << '\n';
	cout << draw << '\n';
	cout << lose << '\n';
	return 0;
}

