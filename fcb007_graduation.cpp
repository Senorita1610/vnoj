#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define ri int
#define pii pair<int,int>

const ll mod = 1e9 + 7;
ll add(ll x, ll y) {
    return (x += y) < mod ? x : x - mod;
}
ll dec(ll x, ll y) {
    return (x -= y) < 0 ? x + mod : x;
}
ll ksm(ll d, ll t, ll res = 1) {
    for (; t; t >>= 1, d = d * d % mod)
        if (t & 1)
            res = res * d % mod;

    return res;
}

int n, m;
const int MAXN = 6e3 + 7;
ll fac[MAXN], ifac[MAXN], base[MAXN], ibase[MAXN], ans;
void init() {
    ibase[0] = base[0] = 1;
    fac[0] = ifac[0] = 1;

    for (ri i = 1; i <= 6000; ++i)
        fac[i] = fac[i - 1] * i % mod, ifac[i] = ifac[i - 1] * ksm(i, mod - 2) % mod;

    for (ri i = 1; i <= 6000; ++i)
        base[i] = base[i - 1] * 2 % mod, ibase[i] = ksm(base[i], mod - 2);
}

ll C(int x, int y) {
    if (x < y)
        return 0;

    return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int main() {
    init();
    scanf("%d%d", &n, &m);

    for (ri k = 0; k <= n && k <= m; ++k) {
        ll res = 0;

        for (ri d = 0; d + k <= n && d + k <= m; ++d) {
            res = add(res, ibase[d] * ifac[n - d - k] % mod * ifac[m - d - k] % mod * C(n + m - 2 * d - 2 * k, d) % mod);
        }

        ans = add(ans, res * base[2 * k] % mod * ifac[k] % mod);
    }

    ans = ans * fac[n] % mod * fac[m] % mod;
    printf("%lld\n", ans - 1);
}

