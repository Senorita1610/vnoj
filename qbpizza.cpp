#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
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
#define N 1010
#define inf 1000000000

const double eps = 1e-5;

struct point {
    double x, y;
};

inline bool cmp(point a, point b) {
    return a.x < b.x;
}

inline point make_point(double _a, double _b) {
    point x;
    x.x = _a; x.y = _b;
    return x;
}

struct line {
    double a, b, c;
    double val(point M) {
        return a*M.x + b*M.y + c;
    }
};

inline line make_line(point A, point B) {
    line d;
    d.a = A.y - B.y;
    d.b = B.x - A.x;
    d.c = A.x*B.y - A.y*B.x;
    return d;
}

inline line make_line2(double a, double b, double c) {
    line d; d.a = a; d.b = b; d.c = c;
    return d;
}

int n, m;
double ymin, ymax;
point a[N];
line b[N];
vector<double> q;
vector<double>::iterator it;
double len[N];
vector<point> l[N], inter;
int dd[2][N], cnt;

inline point intersect(line d1, line d2) {
    d1.a *= d2.b; d1.b = d2.b; d1.c *= d2.b;
    d1.c *= -1; d2.c *= -1;
    double x, y;
    x = (d1.c - d2.c) / (d1.a - d2.a);
    y = (d2.c - d2.a*x) / d2.b;
    return make_point(x, y);
}

inline void Make(line d, int tt) {
    For(i, 1, n) if (d.val(a[i]) * d.val(a[i+1]) <= 0) {
        if (!tt) l[i].clear();
        dd[tt][i] = cnt;
        if (!tt) if (a[i].y == a[i+1].y) l[i].pb(a[i]), l[i].pb(a[i+1]);
        else l[i].pb(intersect(d, b[i]));
    }
}

inline void init() {
    a[0] = a[n]; a[n+1] = a[1];
    For(i, 1, n) b[i] = make_line(a[i], a[i+1]);
    sort(all(q));
    q.erase(unique(all(q)), q.end());
    ymin = q[0]; ymax = q[sz(q)-1];
    For(i, 0, sz(q)-1) {
        line d1 = make_line2(0, 1, -q[i]);
        double y = q[i]; if (q[i] == ymax) y = y - 1; else y = y + 1;
        line d2 = make_line2(0, 1, -y);
        cnt++;
        Make(d1, 0);
        Make(d2, 1);
        inter.clear();
        For(j, 1, n) if (dd[0][j] == dd[1][j]) {
            FOR(it, l[j]) inter.pb(*it);
        }
        sort(all(inter), cmp);
        for(int j = 0; j < sz(inter); j += 2) len[i] = len[i] + inter[j+1].x - inter[j].x;
    }
}

void solve() {
    For(test, 1, m) {
        double y; scanf("%lf", &y);
        if (y == ymax) printf("%.6lf\n",len[sz(q)-1]);
        else if (y == ymin) printf("%.6lf\n",len[0]);
        else if (y < ymin || y > ymax) printf("%.6lf\n",0.0);
        else {
            int j = lower_bound(all(q), y) - q.begin();
            if (q[j] == y) printf("%.6lf\n",len[j]);
            else {
                double h1 = q[j] - y, h2 = y - q[j-1];
                double res = len[j] + h1 / (h1 + h2) * (len[j-1] - len[j]);
                printf("%.6lf\n", res);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    For(i, 1, n) {
        scanf("%lf%lf", &a[i].x, &a[i].y);
        q.pb(a[i].y);
    }
    init();
    solve();
}

