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
#define all(x) x.begin(), x.end()
#define N 15010
#define inf 100000000
int n, k, s[N], d, c, mid, ans, a[N], b[N], t[2][2*N], dem, mm;
ii Q[2*N];

void update(int tt, int i, int val) {
    while (i <= dem) {
        if (tt) t[tt][i] = max(t[tt][i], val);
        else t[tt][i] = min(t[tt][i], val);
        i += i & (-i);
    }
}

int get(int tt, int i) {
    int s; if (tt) s = -1000000; else s = 1000000;
    while (i) {
        if (tt) s = max(s, t[tt][i]);
        else s = min(s, t[tt][i]);
        i -= i & (-i);
    }
    return s;
}

bool check(int x) {
    Q[1] = ii(0, 0);
    int m = 1;
    For(i, 1, n) {
        Q[++m] = ii(s[i], i);
        Q[++m] = ii(s[i] - x, i + n);
    }
    sort(Q+1, Q+1+m);
    dem = 0;
    For(i, 1, m) {
        if (Q[i].fi != Q[i-1].fi) dem++;
        int j = Q[i].se;
        if (j <= n) a[j] = dem;
        else b[j-n] = dem;
    }
    int mi = inf, ma = -inf;
    For(i, 1, dem) {
        t[0][i] = inf; t[1][i] = -inf;
    }
    update(0, dem-a[0]+1, 0); update(1, dem-a[0]+1, 0);
    For(i, 1, n) {
        mi = get(0, dem-b[i]+1) + 1;
        ma = get(1, dem-b[i]+1) + 1;
        update(0, dem-a[i]+1, mi);
        update(1, dem-a[i]+1, ma);
    }
    if (mi > 0 && ma <= n && k >= mi && k <= ma) return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    For(i, 1, n) {
        int x; scanf("%d", &x);
        s[i] = s[i-1] + x;
        mm = max(mm, x);
        if (x >= 0) c += x;
        else d += x;
    }
    bool flag = check(-13528);
    while (d <= c) {
        mid = (d + c) / 2;
        if (check(mid)) {
            ans = mid; c = mid - 1;
        } else d = mid + 1;
    }
    cout << ans;
}

