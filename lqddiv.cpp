#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ff(i, a, b) for(int i = a; i <= b; i++)
#define fo(i, a, b) for(int i = a; i < b; i++)
#define fod(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int INF = 1e9, N = 33;
const ll INFL = 1e18;

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int n, a[N];
ll S, s;
map <ll, int> sub1, sub2, f;
vector <ll> Subset1, Subset2;

int getSum(int mask, int m, int sub) {
	ll res = 0;
	fo(i, 0 + sub, m + sub) {
		if(mask & (1 << (i - sub))) res += a[i + 1]; 
	}
	return res;
}

void backt() {
	int n1 = n / 2, n2 = n - n1;
	fo(mask, 0, (1<<n1)) sub1[getSum(mask, n1, 0)]++; 
	fo(mask, 0, (1<<n2)) sub2[getSum(mask, n2, n1)]++;	
	
	for (map <ll, int>::iterator it = sub1.begin(); it != sub1.end(); ++it) Subset1.pb(it->fi);
	for (map <ll, int>::iterator it = sub2.begin(); it != sub2.end(); ++it) Subset2.pb(it->fi);
}

void solve() {
	ll cur = 0, ans = 0;
	fo(i, 0, Subset1.size()) {
		ll x = Subset1[i];
		if (x > s) break;
		int pos = upper_bound(Subset2.begin(), Subset2.end(), s - x) - 1 - Subset2.begin();
		ll y = Subset2[pos];
		if (cur < x + y) {
			cur = x + y;
			ans = 1LL * sub1[x] * sub2[y];
		}
		else if (cur == x + y) ans += 1LL * sub1[x] * sub2[y];
	}
	if (S - 2 * cur == 0) ans /= 2;
	printf("%lld %lld\n", S - 2 * cur, ans);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n; ff(i, 1, n) { cin >> a[i]; S += a[i]; }
	s = S / 2;
	backt();
	solve();
}

