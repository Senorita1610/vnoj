#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
struct frac {
    ll p, q;
    frac(const ll &_p = 0, const ll &_q = 0): p(_p), q(_q) {
        if (q < 0) {
            p = -p;
            q = -q;
        }
    }
    bool operator<(const frac &f) const {
        return p * f.q < q * f.p;
    }
    bool operator>(const frac &f) const {
        return f < *this;
    }
    double dbl() const {
        return double(p) / q;
    }
} l;
struct point {
    ll x, y;
    point(const ll &x = 0, const ll &y = 0): x(x), y(y) {}
};
frac direction(const point &A, const point &B) {
    return frac(A.y - B.y, A.x - B.x);
}
const ll mxn = 1000005;
ll n, h, i, c = 1;
point L[mxn], R[mxn], a[mxn];
vector <point> H;
pair <frac, frac> inte[mxn >> 1];
int main() {
    scanf("%lld%lld", &n, &h);
    if (n == 3) {
        printf("0");
        return 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
    }
    H.resize(1, *a);
    for (i = 1; i < n; i++) {
        while (H.size() > 1 && direction(H.rbegin()[1], a[i]) < direction(H.back(), a[i])) H.pop_back();
        L[i] = H.back();
        H.push_back(a[i]);
    }
    H.resize(1, a[n - 1]);
    for (i = n - 2; i >= 0; i--) {
        while (H.size() > 1 && direction(H.rbegin()[1], a[i]) > direction(H.back(), a[i])) H.pop_back();
        R[i] = H.back();
        H.push_back(a[i]);
    }
    for (i = 2; i < n - 1; i += 2) {
        /*inte[i].first = {L[i].x * (L[i].y - a[i].y) + (h - L[i].y) * (L[i].x - a[i].x), L[i].y - a[i].y};
        inte[i].second = {a[i].x * (a[i].y - R[i].y) + (h - a[i].y) * (a[i].x - R[i].x), a[i].y - R[i].y};*/
        inte[i / 2 - 1] = {frac(a[i].x * (L[i].y - a[i].y) + (h - a[i].y) * (L[i].x - a[i].x), L[i].y - a[i].y),
            frac(a[i].x * (R[i].y - a[i].y) + (h - a[i].y) * (R[i].x - a[i].x), R[i].y - a[i].y)};
    }
    sort(inte, inte + n / 2 - 1, [](auto &a, auto &b) { return a.second < b.second; });
    /*for (i = 0; i + 1 < n >> 1; i++) {
        printf("[(%lld, %lld), (%lld, %lld)]\n", inte[i].first.p, inte[i].first.q, inte[i].second.p, inte[i].second.q);
    }*/
    l = inte[0].second;
    for (i = 1; i + 1 < n >> 1; i++) {
        if (l < inte[i].first) {
            l = inte[i].second;
            c++;
        }
    }
    printf("%lld", c);
    return 0;
}

