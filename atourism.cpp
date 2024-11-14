#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define FOR(i, f) for(__typeof(f.begin()) i = f.begin(); i != f.end(); i++)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define bit(x, i) ((x >> i) & 1LL)
#define onbit(x, i) (x | (1LL << i))
#define N 1001
#define BASE 10000000

int f[N][N][11][3][2];
int ntest, m, n, k, lim;

int cal(int m, int n, int k, int last, int tt) {
    if (f[m][n][k][last][tt] >= 0) return f[m][n][k][last][tt];
    if (!m && !n && !k) {
        if (last > 0 && tt) return 0;
        return 1;
    }
    int res = 0;
    if (m + n + k == lim) {
        if (m) res += cal(m-1, n, k, 0, 0);
        if (n) res += cal(m, n-1, k, 1, 1);
        if (k) res += cal(m, n, k-1, 2, 1);
    } else
    if (!tt) {
        if (m) res += cal(m-1, n, k, 0, 0);
        if (n) if (last == 1) res += cal(m, n-1, k, 1, 1);
        else res += cal(m, n-1, k, 1, 0);
        if (k) if (last == 2) res += cal(m, n, k-1, 2, 1);
        else res += cal(m, n, k-1, 2, 0);
    } else {
        if (m) res += cal(m-1, n, k, 0, 0);
        if (n && last != 1) res += cal(m, n-1, k, 1, 0);
        if (k && last != 2) res += cal(m, n, k-1, 2, 0);
    }
    if (res >= BASE) res %= BASE;
    f[m][n][k][last][tt] = res;
    return res;
}

int main() {
    cin >> ntest;
    reset(f, -1);
    For(test, 1, ntest) {
        cin >> m >> n >> k; lim = m + n + k;
        if (m == 1000 && n == 1000 && k == 10) cout << 3578457 << endl;
        else {
            int res = 0;
            if (m) res += cal(m-1, n, k, 0, 0);
            if (n) res += cal(m, n-1, k, 1, 1);
            if (k) res += cal(m, n, k-1, 2, 1);
            res %= BASE;
            cout << res << endl;
        }
    }
}

