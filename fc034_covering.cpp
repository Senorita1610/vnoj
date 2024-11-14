#include <bits/stdc++.h>

#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size) memset(array, value, ((size) + 5) * sizeof(decltype(array[0])))
#define memarray(array, value) memset(array, value, sizeof(array))
#define fillarray(array, value, begin, end) fill((array) + (begin), (array) + (end) + 1, value)
#define fillvector(v, value) fill((v).begin(), (v).end(), value)
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v) (sort(vecall(v), greater<decltype(v.back())>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
#define vecunique(v) ((v).resize(unique(vecall(v))-(v).begin()))
using namespace std;
using db = long double;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
const db PI = acos(-1.0L);
const int M = st(20) + 5;

int add(int a, int b) { return (a + b) >= mod ? a + b - mod : a + b; }

int sub(int a, int b) { return (a - b) < 0 ? a - b + mod : a - b; }

int mul(long long a, long long b) { return add(a * b % mod, mod); }

int n;
int f[M], g[M], h[M];
int _2[M];

inline void solve() {
    cin >> n;
    _2[0] = 1;
    for (int i = 1; i < M; ++i)_2[i] = mul(_2[i - 1], 2);
    for (int i = 0; i < st(n); ++i)cin >> f[i];
    for (int i = 0; i < st(n); ++i)cin >> g[i];
    for (int i = 0; i < st(n); ++i)cin >> h[i];
    reverse(f, f + st(n));
    reverse(g, g + st(n));
    reverse(h, h + st(n));

    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < st(n); ++mask) {
            if ((mask >> i) & 1) {
                int now = mask ^ st(i);
                f[now] = add(f[now], f[mask]);
                g[now] = add(g[now], g[mask]);
                h[now] = add(h[now], h[mask]);
            }
        }
    int ans = 0;
    for (int x = 0; x < st(n); ++x) {
        int res = mul(f[x], mul(g[x], h[x]));
        res = mul(res, _2[n - __builtin_popcount(x)]);
        int xi = ((__builtin_popcount(x)) & 1 ? mod - 1 : 1);
        ans = add(ans, mul(xi, res));
    }
    printf("%d\n", ans);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}

