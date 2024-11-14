#include <bits/stdc++.h>
#define lowb(a, r, x) lower_bound(a + 1, a + r + 1, x) - a
#define uppb(a, r, x) upper_bound(a + 1, a + r + 1, x) - a
#define _for(i, a, b) for (ll i = a; i <= b; ++i)
#define for_(i, a, b) for (ll i = a; i >= b; --i)
#define far(i, vec) for (auto i : vec)
#define bdmd int mid = (l + r) >> 1
#define NO nullptr
typedef long double ldb;
typedef long long ll;
typedef double db;
const ll N = 3e5 + 10, INF = 1ll << 40;

class TreeArray {
public:
	ll b[N], mx;
	inline ll lowbit (ll x) { return x & -x; }
	inline void Update (ll x) {
		while (x <= mx) ++b[x], x += lowbit (x);
		return;
	}
	inline ll Query (ll x) {
		ll ans = 0;
		while (x > 0) ans += b[x], x -= lowbit (x);
		return ans;
	}
} ta;

namespace MathBasic {
	inline void GetFactor (ll x, std::vector <ll>& p, std::vector <ll>& k) {
		p.push_back (0), k.push_back (0);
		for (ll i = 2; i * i <= x; ++i) {
			if (!(x % i)) {
				p.push_back (i), k.push_back (0);
				while (!(x % i)) x /= i, ++k[k.size () - 1];
			}
		}
		if (x != 1) p.push_back (x), k.push_back (1);
		return;
	}
	inline ll ExGcd (ll a, ll b, ll& x, ll& y) {
		if (!b) { x = 1, y = 0; return a; }
		ll g = ExGcd (b, a % b, x, y), _x = x;
		x = y, y = _x - (a / b) * y;
		return g;
	}
	inline ll Inv (ll a, ll P) {
		ll x, y;
		ExGcd (a, P, x, y);
		return (x % P + P) % P;
	}
	inline ll FastPow (ll a, ll b, ll Mod = INF) {
		ll ans = 1;
		if (b < 0) a = Inv (a, Mod), b = -b;
		while (b) {
			if (b & 1) ans = ans * a % Mod;
			a = a * a % Mod, b >>= 1;
		}
		return ans;
	}
}

namespace CRT {
	using namespace MathBasic;
	ll a[N], m[N], fac[N], fm[N], in[N], cnt[N];
	std::vector <ll> p, k;
	inline void Pre (ll P) {
		GetFactor (P, p, k);
		ll len = p.size () - 1;
		_for (i, 1, len) fac[i] = fm[i] = 1;
		return;
	}
	inline ll Idx (ll x, ll P) {
		ll idx = 0;
		while (!(x % P)) x /= P, ++idx;
		return idx;
	}
	inline ll DelP (ll x, ll P) {
		while (!(x % P)) x /= P;
		return x;
	}
	inline ll CRT (ll n, ll j, ll ai, ll P) {
		ll ans = 0, len = p.size () - 1;
		++cnt[ai];
		_for (i, 1, len) {
			m[i] = FastPow (p[i], k[i]);
			in[i] += Idx ((n - j) ? (n - j) : 1, p[i]) - Idx (cnt[ai], p[i]);
			fac[i] = fac[i] * DelP ((n - j) ? (n - j) : 1, p[i]) % m[i];
			fm[i] = fm[i] * DelP (cnt[ai], p[i]) % m[i];
			a[i] = FastPow (p[i], in[i], m[i]) * fac[i] % m[i] * Inv (fm[i], m[i]) % m[i];
			ll q = P / m[i];
			ans = (ans + a[i] * q % P * Inv (q, m[i]) % P) % P;
		}
		return ans;
	}
}

namespace SOLVE {
	ll n, P, a[N], ans = 1;
	inline ll rnt () {
		ll x = 0, w = 1; char c = getchar ();
		while (!isdigit (c)) { if (c == '-') w = -1; c = getchar (); }
		while (isdigit (c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar ();
		return x * w;
	}
	inline void In () {
		n = rnt (), P = rnt ();
		_for (i, 1, n) a[i] = rnt (), ta.mx = std::max (ta.mx, a[i]);
		return;
	}
	inline void Solve () {
		CRT::Pre (P);
		for_ (i, n, 1) {
			ll crt = CRT::CRT (n, i, a[i], P);
			ans = (ans + ta.Query (a[i] - 1) % P * crt % P) % P;
			ta.Update (a[i]);
		}
		return;
	}
	inline void Out () {
		printf ("%lld\n", ans);
		return;
	}
}
int main () {
	SOLVE::In ();
	SOLVE::Solve ();
	SOLVE::Out ();
	return 0;
}

