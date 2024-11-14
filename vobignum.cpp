#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1 << x)
#define bit(x, i) ((x >> i) & 1)
#define onbit(x, i) (x | (1 << i))
#define N 1010

const int p[5] = {1000000007, 2038073003, 2038070747, 2038072657, 26513579};

int n, dd[N], a[N][5], q;
int x[5], y[5];
string s;

int main() {
    scanf("%d%d\n", &n, &q);
    For(i, 0, n-1) {
    	getline(cin, s);
        dd[i] = 1; if (s[0] == '-') {
            dd[i] = -1;
            s.erase(0, 1);
        }
        For(j, 0, sz(s)-1) For(jj, 0, 4) a[i][jj] = (ll(a[i][jj]) * 10 + int(s[j]) - int('0')) % p[jj];
        For(jj, 0, 4) a[i][jj] = a[i][jj] * dd[i];
    }
    while (q) {
        q--;
        int i, j, u, v;
        char c1, c2;
        scanf("%d %d %c %d %d %c", &i, &j, &c1, &u, &v, &c2);
        bool flag = true;
        For(jj, 0, 4) {
            if (c1 == '-') x[jj] = (ll(a[i][jj]) - a[j][jj]) % p[jj];
            else if (c1 == '+') x[jj] = (ll(a[i][jj]) + a[j][jj]) % p[jj];
            else x[jj] = (ll(a[i][jj]) * a[j][jj]) % p[jj];
            if (x[jj] < 0) x[jj] += p[jj];

            if (c2 == '-') y[jj] = (ll(a[u][jj]) - a[v][jj]) % p[jj];
            else if (c2 == '+') y[jj] = (ll(a[u][jj]) + a[v][jj]) % p[jj];
            else y[jj] = (ll(a[u][jj]) * a[v][jj]) % p[jj];
            if (y[jj] < 0) y[jj] += p[jj];
            if (x[jj] != y[jj]) flag = false;
        }
        if (flag) printf("YES\n"); else printf("NO\n");
    }
}

