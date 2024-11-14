#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
 
#define FOR(i, a, b) for (ll i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (ll i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (ll i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fi   first
#define se   second
#define all(a) a.begin(), a.end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define endl '\n'
 
struct Point {
	ll x, y;
	Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator == (const Point other) {
		return (x == other.x && y == other.y);
	}
};
 
Point toVec(Point a, Point b) {
	return Point(b.x - a.x, b.y - a.y);
}
 
ll cross(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}
 
bool cw(Point a, Point b, Point c) {
	return (cross(toVec(a, c), toVec(a, b)) > 0);
}
 
bool ccw(Point a, Point b, Point c) {
	return (cross(toVec(a, c), toVec(a, b)) < 0);
}
 
ll area(Point a, Point b, Point c) {
	return abs((a.x - c.x) * (b.y - a.y) - (a.x - b.x) * (c.y - a.y));
}
 
const ll N = 5e4 + 5;
Point P[N];
ll n, ind[N];
 
bool cmp(Point a, Point b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
 
void solve() {
	FOR(i, 1, n) {
		cin >> P[i].x >> P[i].y;
		//cerr << "(" << P[i].x << ", " << P[i].y << ")" << endl;
	}
	if (n <= 2) {
		cout << "0.00" << endl;
		return;
	}
	sort(P + 1, P + 1 + n, cmp);
	Point p1 = P[1], p2 = P[n];
	vector <Point> up, down, cv;
	up.push_back(p1); down.push_back(p1);
	FOR(i, 2, n) {
		if (i == n || cw(p1, P[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], P[i]))
				up.pop_back();
			up.push_back(P[i]);
		}
		if (i == n || ccw(p1, P[i], p2)) {
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], P[i]))
				down.pop_back();
			down.push_back(P[i]);
		}
	}
	ll id = 0;
	for (Point a : up) {
		cv.push_back(a);
		id++;
	}
	FORD(i, down.size() - 2, 1) {
		Point a = down[i];
		cv.push_back(a);
		id++;
	}
	if (id <= 2) {
		cout << "0.00" << endl;
		return;
	}
	REP(i, id) cv.push_back(cv[i]);
	ll res = 0;
	REP(i, id) FOR(j, i + 2, id - 1) {
		ll ans = 0;
		ll l = i + 1, r = j - 1;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			ll S = area(cv[i], cv[mid], cv[j]);
			ans = max(ans, S);
			if (mid != j - 1 && area(cv[i], cv[mid + 1], cv[j]) > S) l = mid + 1;
			else if (mid != i + 1 && area(cv[i], cv[mid - 1], cv[j]) > S) r = mid - 1;
			else break;
		}
		l = j + 1, r = i + id - 1;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			ll S = area(cv[i], cv[j], cv[mid]);
			ans = max(ans, S);
			if (mid != i + id - 1 && area(cv[i], cv[j], cv[mid + 1]) > S) l = mid + 1;
			else if (mid != j + 1 && area(cv[i], cv[j], cv[mid - 1]) > S) r = mid - 1;
			else break;
		}
		res = max(res, ans);
	}
	cout << fixed << setprecision(2) << 1.0 * res / 2 << endl;
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	clock_t tStart = clock();
 
	while (cin >> n && n != -1) solve();
 
	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}

