#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

#ifndef local
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;

const uint64_t B = 1e10;

char buf[9000000], *out = buf + sizeof buf;
alignas(64) char digit[40000];

inline void print4(uint64_t x, int k) {
    out -= k, memcpy(out, digit + x * 4 + 4 - k, k);
}
struct {
    int len;
    uint64_t a[900];
    inline void mul(uint64_t x) {
        uint64_t jw = 0;
        rep(i, 0, len) jw += a[i] * x, a[i] = jw % B, jw /= B;
        if(jw) a[++len] = jw;
    }
    inline int mod(uint32_t x) {
        uint64_t r = 0;
        per(i, len, 0) r = (r * B + a[i]) % x;
        return r;
    }
    inline void div(uint32_t x) {
        uint64_t r = 0;
        per(i, len, 0) r = r * B + a[i], a[i] = r / x, r %= x;
        len -= !a[len];
    }
    inline void print() {
        For(i, 0, len) {
            print4(a[i] % 10000, 4);
            print4(a[i] / 10000 % 10000, 4);
            print4(a[i] / 100000000, 2);
        }
        uint64_t x = a[len];
        while(x) *--out = 48 + x % 10, x /= 10;
    }
} x, y;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    rep(i, 0, 9999) {
        digit[i * 4 + 0] = 48 + i / 1000;
        digit[i * 4 + 1] = 48 + i / 100 % 10;
        digit[i * 4 + 2] = 48 + i / 10 % 10;
        digit[i * 4 + 3] = 48 + i % 10;
    }
    int n, p[1008];
    cin >> n;
    rep(i, 1, n) cin >> p[i];
    x.a[0] = y.a[0] = 1;
    bool zero = 0;
    per(i, n, 1) {
        if(zero) { out -= 4, memcpy(out, "0/1\n", 4); continue; }
        uint32_t d = __gcd(p[i], x.mod(p[i]));
        y.mul(p[i] / d), x.div(d);
        *--out = '\n', y.print(), *--out = '/', x.print();
        if(--p[i]) {
            d = __gcd(p[i], y.mod(p[i]));
            x.mul(p[i] / d), y.div(d);
        } else zero = 1;
    }
    fwrite(out, 1, buf + sizeof buf - out, stdout);
}

