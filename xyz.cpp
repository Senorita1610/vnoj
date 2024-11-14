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
#define bit(x, i) ((x >> i) & 1LL)
#define onbit(x, i) (x | (1LL << (i-1)))
#define N 32
#define BASE 1000000

int n, l;
int a[2][N], nex[2][N];
int f[N][N][N][2][2];

void add(int &a, int b) {
    a += b; if (a >= BASE) a -= BASE;
}

int main() {
    scanf("%d%d\n", &n, &l);
    For(t, 0, 1) {
        For(i, 1, 5) {
            For(j, 1, l) {
                char c; scanf("%c", &c);
                if (c == '#') a[t][j] = onbit(a[t][j], i);
            }
            scanf("\n");
        }
        For(i, 2, l) {
            int j = nex[t][i-1];
            while (j && a[t][j+1] != a[t][i]) j = nex[t][j];
            if (a[t][j+1] == a[t][i]) nex[t][i] = j+1; else nex[t][i] = 0;
        }
    }
    f[0][0][0][0][0] = 1;
    int res = 0;
    For(i, 1, n+1) For(l1, 0, l-1) For(l2, 0, l-1)
    For(t1, 0, 1) For(t2, 0, 1) if (t1 + t2 <= 1) {
    For(tt, 0, two(5)-1) {
        int j1 = l1, j2 = l2;
        while (j1 && a[0][j1+1] != tt) j1 = nex[0][j1];
        while (j2 && a[1][j2+1] != tt) j2 = nex[1][j2];
        if (a[0][j1+1] == tt) j1++; else j1 = 0;
        if (a[1][j2+1] == tt) j2++; else j2 = 0;
        int newt1 = t1, newt2 = t2;
        if (j1 == l) newt1 |= 1, j1 = nex[0][j1];
        if (j2 == l) newt2 |= 1, j2 = nex[1][j2];
        add(f[i][j1][j2][newt1][newt2], f[i-1][l1][l2][t1][t2]);
    }
        if (i == n+1 && t1 + t2 == 1) {
            add(res, f[i-1][l1][l2][t1][t2]);
        }
    }
    cout << res;
}

