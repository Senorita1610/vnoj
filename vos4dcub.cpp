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
#define reset(f,x) memset(f,x,sizeof(f))
#define N 51

int X, Y, Z, T, C, a[N][N][N][N], b[3][4];
ll s[N][N][N][N], res;

ll sum(int x1, int y1, int z1, int t1, int x2, int y2, int z2, int t2) {
    return s[x2][y2][z2][t2] + s[x1][y1][z1][t1] + s[x1][y1][z2][t2] + s[x1][y2][z1][t2]
         + s[x1][y2][z2][t1] + s[x2][y1][z1][t2] + s[x2][y1][z2][t1] + s[x2][y2][z1][t1]
         - s[x1][y2][z2][t2] - s[x2][y1][z2][t2] - s[x2][y2][z1][t2] - s[x2][y2][z2][t1]
         - s[x1][y1][z1][t2] - s[x1][y1][z2][t1] - s[x1][y2][z1][t1] - s[x2][y1][z1][t1];
}

ll cal(int x1, int y1, int z1, int t1, int x2, int y2 ,int z2, int t2) {
    return -(-a[x2][y2][z2][t2] + s[x1][y1][z1][t1] + s[x1][y1][z2][t2] + s[x1][y2][z1][t2]
         + s[x1][y2][z2][t1] + s[x2][y1][z1][t2] + s[x2][y1][z2][t1] + s[x2][y2][z1][t1]
         - s[x1][y2][z2][t2] - s[x2][y1][z2][t2] - s[x2][y2][z1][t2] - s[x2][y2][z2][t1]
         - s[x1][y1][z1][t2] - s[x1][y1][z2][t1] - s[x1][y2][z1][t1] - s[x2][y1][z1][t1]);
}

void solve() {
    For(x, 1, X) For(y, 1, Y) For(z, 1, Z) For(t, 1, T) {
        s[x][y][z][t] = cal(x - 1, y - 1, z - 1, t - 1, x, y, z, t);
        int c = min(min(min(x, y), z), t); int bound = c;
        if (c > 0) {
            int d = 1, mid, ans = -1;
            while (d <= c) {
                mid = (d + c) / 2;
                ll S = sum(x, y, z, t, x - mid, y - mid, z - mid, t - mid);
                if (S >= C) {
                    ans = mid; c = mid - 1;
                } else d = mid + 1;
            }
            if (ans > 0) res += bound - ans + 1;
        }
    }
    cout << res;
}

int main() {
    scanf("%d%d%d%d%d\n", &X, &Y, &Z, &T, &C);
    For(x, 1, X) For(y, 1, Y) {
        char c;
        For(z, 1, Z) {For(t, 1, T) {
            scanf("%c", &c); a[x][y][z][t] = c - '0';
        }
        scanf("\n");
        }
    }
    solve();
}

