#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define N 2010

char a[N][N];
int h[N], m, n, p[N], top;
ll f[N], sumX[N];
ll res, kq;

ll tong(int x) {
    return (x * (x + 1)) / 2;
}

void Cal() {
    reset(h, 0);
    For(i, 1, m) {
        For(j, 1, n) if (a[i][j] == '1') h[j]++; else h[j] = 0;
        top = 0;
        For(j, 1, n) {
            while (top && h[j] <= h[p[top]]) top--;
            int jj = p[top]; p[++top] = j;
            int Y = j - jj, X = h[j];
            f[j] = tong(X) * tong(Y);
            f[j] += f[jj] + sumX[jj] * Y;
            sumX[j] =  sumX[jj] + tong(X) * Y;
            res += f[j];
        }
    }
}

void solve() {
    Cal();
    For(i, 1, m) For(j, 1, n) if (a[i][j] == '1') a[i][j] = '0'; else a[i][j] = '1';
    Cal();
    For(i, 1, m) For(j, 1, n) kq += tong(i) * tong(j);
    cout << kq - res;
}

int main() {
    scanf("%d%d", &m, &n);
    For(i, 1, m) scanf("%s\n", a[i]+1);
    solve();
}

