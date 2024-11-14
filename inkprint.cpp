#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
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
#define pb push_back
#define sz(s) int(s.size())
#define reset(f,x) memset(f,x,sizeof(f))
#define N 26
#define BASE 777777777
#define base 100000000

struct matrix {
    int h[N][N];
};

struct bignum {
    int h[30];
};

int n,a[26],f[200];
char s[201];
bignum m,b;
matrix aa,bb;

matrix operator * (const matrix &a, const matrix &b) {
    matrix c;
    For(i,0,n-1) For(j,0,n-1) {
        c.h[i][j] = 0;
        ll x = 0;
        For(k,0,n-1) {
            x = x + ll(a.h[i][k]) * b.h[k][j];
            if (x >= BASE) x %= BASE;
        }
        c.h[i][j] = x;
    }
    return c;
}

bignum operator - (const bignum &a, const bignum &b) {
    int nho = 0;
    bignum c;
    reset(c.h,0);
    c.h[0] = a.h[0];
    For(i,1,a.h[0]) {
        int x = a.h[i] - nho;
        if (i <= b.h[0]) x-= b.h[i];
        if (x < 0) {
            x += base;
            nho = 1;
        } else nho = 0;
        c.h[i] = x;
    }
    while (!c.h[c.h[0]] && c.h[0] > 1) c.h[0]--;
    return c;
}

bignum operator / (const bignum &a, const int &b) {
    bignum c;
    reset(c.h,0);
    ll nho = 0,s = 0;
    c.h[0] = a.h[0];
    Rep(i,a.h[0],1) {
        nho = nho * base + a.h[i];
        s = nho / b;
        nho = nho % b;
        c.h[i] = s;
    }
    while (c.h[0] > 1 && !c.h[c.h[0]]) c.h[0]--;
    return c;
}

int cmp(const bignum &a,const bignum &b) {
    if (a.h[0] > b.h[0]) return 1;
    if (b.h[0] > a.h[0]) return -1;
    Rep(i,a.h[0],1) {
        if (a.h[i] > b.h[i]) return 1;
        if (a.h[i] < b.h[i]) return -1;
    }
    return 0;
}

void solve() {
    f[0] = 1;
    For(i,1,n-1) For(j,1,n) if (i >= a[j]) f[i] = (f[i] + f[i-a[j]]) % BASE;
    int len = strlen(s+1);
    m.h[0] = 0;
    for(int i = len-7; i > 0; i -= 8) {
        int x = 0;
        For(j,0,7) x = x * 10 + int(s[i+j]) - int('0');
        m.h[0]++; m.h[m.h[0]] = x;
    }
    if (len % 8) {
        m.h[0]++; int x = 0;
        For(j,1, len % 8) x = x * 10 + int(s[j]) - int('0');
        m.h[m.h[0]] = x;
    }
    b.h[0] = 1; b.h[1] = n-1;
    if (cmp(m,b) <= 0) {
        int x = 0;
        For(i,1,m.h[0]) x = x * base + m.h[i];
        cout << f[x];
        return;
    }
    m = m - b;
    reset(aa.h,0); reset(bb.h,0);
    For(j,0,n-2) For(i,0,n-1) {
        if (i == j+1) bb.h[i][j] = 1;
    }
    For(i,1,n) bb.h[n-a[i]][n-1]++;
    For(i,0,n-1) aa.h[0][i] = f[i];
    bignum oo; oo.h[0] = 1; oo.h[1] = 0;
    bignum o1; o1.h[0] = 1; o1.h[1] = 1;
    matrix res;
    reset(res.h,0);
    For(i,0,n-1) res.h[i][i] = 1;
    while (cmp(m,oo) != 0) {
        if (m.h[1] % 2) res = res * bb;
        m = m / 2;
        bb = bb * bb;
    }
    aa = aa * res;
    cout << aa.h[0][n-1] << "\n";
}

int main() {
    cin >> n >> (s+1);
    For(i,1,n) cin >> a[i];
    solve();
}

