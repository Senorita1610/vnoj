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
#define N 1010

int m, n, a[N][N], mx[N], my[N];
vector<int> ke[2][N];
int trace[N], q[N + N], lef, righ;
bool s[N+N];
vector<int> h, c;

int FindPath() {
    lef = righ = 0;
    For(i, 1, m) if (!mx[i]) q[++righ] = i;
    reset(trace, 0);
    while (lef < righ) {
        int i = q[++lef];
        FOR(j, ke[0][i]) if (!trace[*j]) {
            trace[*j] = i;
            if (!my[*j]) return *j;
            q[++righ] = my[*j];
        }
    }
    return 0;
}

void IncFlow(int f) {
    int next, x;
    do {
        x = trace[f];
        next = mx[x];
        mx[x] = f;
        my[f] = x;
        f = next;
    } while (f);
}

int main() {
    scanf("%d%d", &m, &n);
    For(i, 1, m) For(j, 1, n) scanf("%d", &a[i][j]);
    For(i, 1, m) For(j, 1, n) if (!a[i][j]) {
        ke[0][i].pb(j); ke[1][j].pb(i);
    }
    while (1) {
        int f = FindPath();
        if (!f) break;
        IncFlow(f);
    }
    reset(s, true);
    For(j, 1, n) if (trace[j]) s[j+m] = false;
    For(i, 1, m) if (mx[i] && s[mx[i]+m]) s[i] = false;
    For(i, 1, m) if (s[i]) h.pb(i);
    For(j, 1, n) if (s[j+m]) c.pb(j);
    if (sz(h) + sz(c) <= max(m, n)) cout << 0 << ' ' << 0;
    else {
        int res = 0;
        cout << sz(h) << ' ' << sz(c) << endl;
        FOR(x, h) if (*x > sz(h)) res++;
        FOR(x, c) if (*x > sz(c)) res++;
        cout << res << endl;
        int i = 1;
        FOR(x, h) if (*x > sz(h)) {
            while (i <= m && s[i]) i++;
            s[i] = true;
            cout << "R " << i << ' ' << *x << endl;
        }
        int j = 1;
        FOR(x, c) if (*x > sz(c)) {
            while (j <= n && s[j+m]) j++;
            s[j+m] = true;
            cout << "C " << j << ' ' << *x << endl;
        }
    }
}

