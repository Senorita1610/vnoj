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
#define N 110

int a[N][N], m, n, b[N][N];
vector<ii> kq;

void dao(int i, int j) {
    For(u, i, i+2) For(v, j, j+2) b[u][v] = 1 - b[u][v];
}

int main() {
    cin >> m >> n;
    For(i, 1, m) For(j, 1, n) cin >> a[i][j];
    For(i, 1, m-2) For(j, 1, n-2)
        if (a[i][j] != b[i][j]) {
            dao(i, j);
            kq.pb(ii(i, j));
        }
    bool ok = true;
    For(i, 1, m) For(j, 1, n)
        ok &= (a[i][j] == b[i][j]);
    if (!ok) cout << -1;
    else {
        cout << sz(kq) << endl;
        For(i, 0, sz(kq)-1) cout << kq[i].fi << ' ' << kq[i].se << endl;
    }
}

