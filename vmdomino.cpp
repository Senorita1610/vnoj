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
#define N 17

struct matrix {
    int h[56][56];
};

int m, n, a[N][N], BASE, k, L, T;
int f[2][1 << 17];
vector<int> s[2];
matrix base, g, chan, le;

void add(int &a, int b) {
    a += b; if (a >= BASE) a -= BASE;
}

matrix operator *(matrix a, matrix b) {
    matrix c;
    REP(i, L) REP(j, L) {
        c.h[i][j] = 0;
        REP(k, L) add(c.h[i][j], (ll(a.h[i][k]) * b.h[k][j]) % BASE);
    }
    return c;
}

matrix poww(matrix a, int n) {
    matrix res; reset(res.h, 0);
    REP(i, L) res.h[i][i] = 1;
    while (n) {
        if (n & 1) res = res * a;
        n >>= 1;
        a = a * a;
    }
    return res;
}

void sub1() {
    reset(f, 0);
    int mask = 0;
    For(j, 1, n) if ((1 + j) % 2 == 0) mask = onbit(mask, j);
    f[0][mask] = 1;
    int T = two(n) - 1;
    int t = 0;
    For(i, 1, m) For(j, 1, n) {
        t = 1 - t; reset(f[t], 0);
        For(mask, 0, T) if (f[1-t][mask]) {
            int upper = getbit(mask, j), left;
            if (j > 1) left = getbit(mask, j-1);
            else if ((i + j) % 2) left = 0; else left = 1;
            if ((i + j) % 2) {
                int newmask = onbit(mask, j);
                add(f[t][newmask], f[1-t][mask]);
                if (!max(upper, left) && !a[i][j]) {
                    newmask = offbit(mask, j);
                    add(f[t][newmask], f[1-t][mask]);
                }
            } else {
                int newmask = offbit(mask, j);
                add(f[t][newmask], f[1-t][mask]);
                if (min(upper, left) && !a[i][j]) {
                    newmask = onbit(mask, j);
                    add(f[t][newmask], f[1-t][mask]);
                }
            }
        }
    }
    int res = 0;
    For(mask, 0, T) add(res, f[t][mask]);
    cout << res << endl;
}

void init() {
    T = two(n);
    REP(mask, T) {
        bool ok = true;
        For(j, 2, n)
            if (j % 2 && getbit(mask, j) < getbit(mask, j-1)) ok = false;
            else if (j % 2 == 0 && getbit(mask, j) > getbit(mask, j-1)) ok = false;
        if (ok) s[0].push_back(mask);
        ok = true;
        For(j, 2, n)
            if (j % 2 && getbit(mask, j) > getbit(mask, j-1)) ok = false;
            else if (j % 2 == 0 && getbit(mask, j) < getbit(mask, j-1)) ok = false;
        if (ok) s[1].push_back(mask);
    }
    L = sz(s[0]);
    T = sz(s[0]);
}

bool check(int mask_up, int mask_down, int i) {
    For(j, 1, n) {
        int upper = getbit(mask_up, j), left;
        if (j > 1) left = getbit(mask_down, j-1);
        else if ((i + j) % 2) left = 0; else left = 1;
        //cout << upper << ' ' << left << ' ' << getbit(mask_down, j) << endl;
        if ((i + j) % 2 && getbit(mask_down, j) < max(left, upper)) return false;
        if ((i + j) % 2 == 0 && getbit(mask_down, j) > min(left, upper)) return false;
    }
    return true;
}

void build_matrix() {
    REP(i, T) REP(j, T) {
        if (check(s[1][j], s[0][i], 0)) chan.h[j][i] = 1;
        if (check(s[0][i], s[1][j], 1)) le.h[i][j] = 1;
    }
    REP(i, T) g.h[0][i] = 1;
}

void sub2() {
    init();
    build_matrix();
    if (m > 1) {
       base = chan * le;
       base = poww(base, (m-1) / 2);
       if (m % 2 == 0) base = base * chan;
       g = g * base;
    }
    int res = 0;
    REP(i, L) add(res, g.h[0][i]);
    cout << res << endl;
}

int main() {
    scanf("%d", &BASE);
    int t;
    scanf("%d%d%d", &m, &n, &t);
    For(i, 1, t) {
        int u, v; scanf("%d%d", &u, &v); a[u][v] = 1;
    }
    sub1();
    scanf("%d%d", &m, &n);
    swap(m, n);
    sub2();
}

