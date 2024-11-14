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
#define N 100010

const ll inf = 1000000000000000000;

struct line {
    ll a, b;
    double x, y;
};

struct pizza {
    int t, a, b;
};

int n, cost, top;
pizza s[N];
ll f[N], A[N], B[N], C[N];
line st[N];

bool cmp(pizza a, pizza b) {
    return a.t < b.t;
}

void init() {
    For(i, 1, n) {
        A[i] = A[i-1] + s[i].a;
        B[i] = B[i-1] + s[i].b;
        C[i] = C[i-1] + ll(s[i].b) * s[i].t;
    }
}

void sub1() {
    For(i, 1, n) {
        int x = s[i].t;
        Rep(j, i-1, 0) {
            ll c = -cost + C[i] + A[i] - B[i]*x;
            ll b = -A[j] - C[j] + f[j];
            ll a = B[j];
            f[i] = max(f[i], a*x + b + c);
        }
    }
    cout << f[n];
}

ll Find(int x) {
    int l = 0, r = top, mid, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (st[mid].x <= x) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return st[ans].a*x + st[ans].b;
}

void push(ll a1, ll b1) {
    while (top) {
        ll a2 = st[top-1].a, b2 = st[top-1].b;
        double xx = (double(b2)-b1)/(a1-a2);
        double yy = xx*a1 + b1;
        if (xx <= st[top].x) top--;
        else break;
    }
    top++; st[top].a = a1; st[top].b = b1;
    ll a2 = st[top-1].a, b2 = st[top-1].b;
    double xx = (double(b2)-b1)/(a1-a2);
    double yy = xx*a1 + b1;
    st[top].x = xx; st[top].y = yy;
}

void sub2() {
    st[0].a = 0; st[0].b = 0; st[0].x = 0; st[0].y = 0;
    top = 0;
    For(i, 1, n) {
        int x = s[i].t;
        f[i] = -cost + C[i] + A[i] - B[i]*x;
        f[i] += Find(x);
        ll a = B[i], b = -A[i] - C[i] + f[i];
        push(a, b);
    }
    cout << f[n];
}

int main() {
    scanf("%d%d", &n, &cost);
    For(i, 1, n) scanf("%d%d%d", &s[i].t, &s[i].a, &s[i].b);
    sort(s+1, s+n+1, cmp);
    For(i, 0, n) f[i] = -inf; f[0] = 0;
    init();
    sub2();
}

