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

int n;
ll a[N][N], sum[N], x;

int main() {
    cin >> n;
    For(i, 1, n) For(j, 1, n) {
        cin >> a[i][j];
        sum[i] += a[i][j];
    }
    a[1][1] = sum[1]*(n-1) - sum[1];
    For(i, 2, n) a[1][1] -= sum[i];
    a[1][1] /= (n-1); a[1][1] = - a[1][1];
    x = a[1][1] + sum[1];
    For(i, 2, n) a[i][i] = x - sum[i];
    For(i, 1, n) {
        For(j, 1, n) cout << a[i][j] << ' ';
        cout << endl;
    }
}

