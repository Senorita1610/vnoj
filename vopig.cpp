#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define ld long double
#define pb push_back
#define all(x) x.begin(), x.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define sz(s) int(s.size())
#define two(i) (ull(1) << i)
#define bit(x, i) ( (x >> i) & 1 )
#define onbit(x, i) ( x | (1 << i ) )
#define N 100010

ull n, m, a[N], f[N], res, mm, b[N];
int dem[1048577], g[1048577];

void sub1() {
    cout << trunc(log(n+1) / log(2));
}

void sub2() {
    int len = trunc(log(n+1) / log(2));
    mm = m;
    int bit0 = 0, bit1 = 0;
    For(i, 0, len-1) if (bit(m, i)) bit1++; else bit0++;
    ll res = ll(two(bit0)) * (bit1+1) - 1;
    cout << res << endl;
}

void sub3() {
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) {
        a[i] = a[i] & m;
    }
    sort(a+1, a+n+1);
    //For(i, 1, n) cout << a[i] << ' '; cout << endl;
    For(i, 1, n) {
        f[i] = 1;
        For(j, 1, i-1) if ((a[i] | a[j]) == a[i]) f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << res << endl;
}

void sub4() {
    For(i, 1, n) {
        cin >> a[i];
        a[i] = a[i] & m;
    }
    For(i, 1, n) {
        int sl = -1;
        For(j, 0, 30) if (bit(m, j)) {
            sl++;
            if (bit(a[i], j)) b[i] += two(sl);
        }
        dem[b[i]]++;
    }
    For(tt, 0, two(20)-1) {
        g[tt] += dem[tt];
        For(j, 0, 19) if (!bit(tt, j)) g[onbit(tt,j)] = max(g[onbit(tt, j)], g[tt]);
    }
    cout << g[two(20)-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (n >= 1000000000 && m == two(60)-1) sub1();
    else
    if (n >= 1000000000)
    sub2();
    else if (n <= 5000)
    sub3();
    else
    sub4();
}

