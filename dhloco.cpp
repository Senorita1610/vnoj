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
#define onbit(x, i) (x | (1LL << i))

struct matrix {
    int h[3][3];
};

ll n;
int BASE;
matrix base, f;

matrix operator *(matrix a, matrix b) {
    matrix c;
    REP(i, 3) REP(j, 3) {
        c.h[i][j] = 0;
        REP(k, 3) c.h[i][j] += (a.h[i][k] * b.h[k][j]) % BASE;
        c.h[i][j] %= BASE;
    }
    return c;
}

matrix mu(matrix a, ll n) {
    if (n == 1) return a;
    matrix c = mu(a, n / 2);
    c = c * c;
    if (n % 2) c = c * a;
    return c;
}

int main() {
    cin >> n >> BASE;
    f.h[0][0] = 1 % BASE;
    f.h[0][1] = 2 % BASE;
    f.h[0][2] = 4 % BASE;
    if (n <= 3) cout << f.h[0][n-1];
    else {
        base = (matrix){
            0, 0, 1,
            1, 0, 1,
            0, 1, 1
        };
        base = mu(base, n-3);
        f = f * base;
        cout << f.h[0][2];
    }
}

