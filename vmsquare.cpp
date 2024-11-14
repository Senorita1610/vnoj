#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, f) for(__typeof(f.begin()) i = f.begin(); i != f.end(); i++)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define getbit(x, i) ((x >> (i-1)) & 1LL)
#define onbit(x, i) (x | (1LL << (i-1)))
#define offbit(x, i) (x & ~(1 << (i-1)))

ll xa, ya, xb, yb, xc, yc, xd, yd, s, cnt, res;

ll gcd(ll a, ll b) {
    if (!a) return b;
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
    s = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
    cnt = gcd(abs(xa-xb), abs(ya-yb)) + gcd(abs(xb-xc), abs(yb-yc)) + gcd(abs(xc-xd), abs(yc-yd)) + gcd(abs(xd-xa), abs(yd-ya));
    res = s - cnt / 2 + 1;
    cout << res;
}

