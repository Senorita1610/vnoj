#include <bits/stdc++.h>
#define fq(i,a,b) for (int i = (a); i <= (b); i++)
using namespace std;
#define int long long
inline int rd () {
	int f = 1;
	char ch = getchar ();
	while (!isdigit (ch)) (ch == '-' ? (f = -1) : 0), ch = getchar ();
	int num = 0;
	while (isdigit (ch)) num = num * 10 + ch - '0', ch = getchar ();
	return num * f;
}
#define d rd ()

const int maxn = 550;
const int mod = 1e9+7;
int n = d, k = d, h[maxn];
int l[maxn], r[maxn], sk[maxn], top;
int mul[1001000], invm[1001000];
bool cmp (int a, int b) {
    return h[a] < h[b];
}
int f[maxn][maxn], g[maxn], sz[maxn];
void prew (int u) {
    sz[u] = 1;
    if (l[u]) prew (l[u]), sz[u] += sz[l[u]];
    if (r[u]) prew (r[u]), sz[u] += sz[r[u]];
}
int A (int N, int M) {
    if (M > N) return 0;
    return mul[N] * invm[N - M] % mod;
}
int sol (int N, int M, int K) {
    return A (N, K) * A (M, K) % mod * invm[K] % mod;
}
void dfs (int u, int low) {
    int uh = h[u] - low;
    if (!l[u] && !r[u]) {
        f[u][0] = 1;
        fq (i, 1, k) f[u][i] = sol (sz[u], uh, i);
        return;
    }
    if (!l[u] || !r[u]) {
        int v;
        if (!l[u]) v = r[u];
        else v = l[u];
        dfs (v, h[u]);
        memset (g, 0, sizeof g);
        g[0] = 1;
        fq (i, 1, k) fq (j, 0, i) g[i] = (g[i] + f[0][j] * f[v][i - j]) % mod;
        f[u][0] = 1;
        fq (i, 1, k) fq (j, 0, i) f[u][i] = (f[u][i] + g[j] * sol (uh, sz[u] - j, i - j)) % mod;
        return;
    }
    dfs (l[u], h[u]);
    dfs (r[u], h[u]);
    memset (g, 0, sizeof g);
    g[0] = 1;
    fq (i, 1, k) fq (j, 0, i) g[i] = (g[i] + f[l[u]][j] * f[r[u]][i - j]) % mod;
    f[u][0] = 1;
    fq (i, 1, k) fq (j, 0, i) f[u][i] = (f[u][i] + g[j] * sol (uh, sz[u] - j, i - j)) % mod;
}
int power (int a, int b, int p) {
	int c = 1;
	while (b) {
		if (b & 1) c = c * a % p;
		a = a * a % p;
		b >>= 1;
	} return c;
}
signed main () {
    mul[0] = invm[0] = 1;
    fq (i, 1, 1000000) {
        mul[i] = mul[i - 1] * i % mod;
        invm[i] = invm[i - 1] * power (i, mod - 2, mod) % mod;
    }
    fq (i, 1, n) h[i] = d;
    fq (i, 1, n) {
        int kk = top;
        while (kk && h[sk[kk]] > h[i]) --kk;
        if (kk) r[sk[kk]] = i;
        if (kk != top) l[i] = sk[kk + 1];
        sk[top = ++kk] = i;
    } prew (sk[1]); f[0][0] = 1;
    dfs (sk[1], 0); cout << f[sk[1]][k] << endl;
	return 0;
}

