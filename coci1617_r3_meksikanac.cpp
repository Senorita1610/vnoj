#include <stdio.h>
#include <stdlib.h>
 
#define N	501
#define M	501
#define L_	20	/* L_ = ceil(log2(N * 2 * M * 2)) */
#define N_	(1 << L_)
#define K	10000
#define INF	0x3f3f3f3f
#define MD	469762049	/* MD = 56 * 2^23 + 1 */
 
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
 
int *wwu[L_ + 1], *wwv[L_ + 1], V;
 
long long power(long long a, int k) {
	long long p = 1;
 
	while (k) {
		if (k & 1)
			p = p * a % MD;
		a = a * a % MD;
		k >>= 1;
	}
	return p;
}
 
void init() {
	int l, u, v;
 
	V = power(N_, MD - 2), u = power(3, MD - 1 >> L_), v = power(u, MD - 2);
	for (l = L_; l > 0; l--) {
		int n = 1 << l, m = n >> 1, i;
 
		wwu[l] = (int *) malloc(m * sizeof *wwu[l]);
		wwv[l] = (int *) malloc(m * sizeof *wwv[l]);
		wwu[l][0] = wwv[l][0] = 1;
		for (i = 1; i < m; i++) {
			wwu[l][i] = (long long) wwu[l][i - 1] * u % MD;
			wwv[l][i] = (long long) wwv[l][i - 1] * v % MD;
		}
		u = (long long) u * u % MD;
		v = (long long) v * v % MD;
	}
}
 
void ntt_(int *aa, int l, int inverse) {
	if (l) {
		int n = 1 << l, m = n >> 1, *ww = inverse ? wwv[l] : wwu[l], i, j;
 
		ntt_(aa, l - 1, inverse), ntt_(aa + m, l - 1, inverse);
		for (i = 0; (j = i + m) < n; i++) {
			int a = aa[i], b = (long long) aa[j] * ww[i] % MD;
 
			if ((aa[i] = a + b) >= MD)
				aa[i] -= MD;
			if ((aa[j] = a - b) < 0)
				aa[j] += MD;
		}
	}
}
 
void ntt(int *aa, int inverse) {
	int i, j;
 
	for (i = 0, j = 1; j < N_; j++) {
		int b = N_ >> 1, tmp;
 
		while ((i ^= b) < b)
			b >>= 1;
		if (i < j)
			tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
	}
	ntt_(aa, L_, inverse);
}
 
char fly[N][M], swatter[N][M], kk[N][M];
 
void paint(int i1, int j1, int i2, int j2) {
	int i, j;
 
	if (i1 > i2 || i1 == i2 && j1 > j2) {
		paint(i2, j2, i1, j1);
		return;
	}
	if (i1 == i2) {
		i = i1;
		for (j = j1; j <= j2; j++)
			swatter[i][j] = 1;
	} else {
		swatter[i1][j1] = swatter[i2][j2] = 1;
		for (i = i1; i < i2; i++) {
			j = i1 + (i - i1) * (j2 - j1) / (i2 - i1);
			while ((i2 - i1) * (j - j1) - (i - i1) * (j2 - j1) > 0)
				j--;
			while ((i2 - i1) * (j + 1 - j1) - (i - i1) * (j2 - j1) <= 0)
				j++;
			if ((i2 - i1) * (j - j1) - (i - i1) * (j2 - j1) == 0)
				swatter[i][j] = 1;
			kk[i][j] ^= 1;
		}
	}
}
 
int main() {
	static int ii[K], jj[K], aa[N_], bb[N_];
	int n, m, k, h, i, j, imn, imx, jmn, jmx, ans;
 
	init();
	scanf("%d%d%d", &n, &m, &k), n++, m++;
	while (k--) {
		scanf("%d%d", &i, &j);
		fly[i][j] = 1;
	}
	scanf("%d", &k);
	imn = INF, imx = -INF, jmn = INF, jmx = -INF;
	for (h = 0; h < k; h++) {
		scanf("%d%d", &ii[h], &jj[h]);
		imn = min(imn, ii[h]), imx = max(imx, ii[h]);
		jmn = min(jmn, jj[h]), jmx = max(jmx, jj[h]);
	}
	if (imx - imn > n || jmx - jmn > m) {
		printf("0\n");
		return 0;
	}
	for (h = 0; h < k; h++)
		ii[h] -= imn, jj[h] -= jmn;
	for (h = 0; h < k; h++) {
		int i1 = ii[h], j1 = jj[h], i2 = ii[(h + 1) % k], j2 = jj[(h + 1) % k];
 
		paint(i1, j1, i2, j2);
	}
	for (i = 0; i < n; i++)
		for (j = m - 2; j >= 0; j--)
			kk[i][j] ^= kk[i][j + 1];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (kk[i][j])
				swatter[i][j] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (fly[i][j])
				aa[i * m * 2 + j] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (swatter[i][j])
				bb[(n - 1 - i) * m * 2 + (m - 1 - j)] = 1;
	ntt(aa, 0), ntt(bb, 0);
	for (i = 0; i < N_; i++)
		aa[i] = (long long) aa[i] * bb[i] % MD;
	ntt(aa, 1);
	for (i = 0; i < N_; i++)
		aa[i] = (long long) aa[i] * V % MD;
	ans = 0;
	for (i = 0; i + imx - imn < n; i++)
		for (j = 0; j + jmx - jmn < m; j++)
			if (!aa[(n - 1 + i) * m * 2 + (m - 1 + j)])
				ans++;
	printf("%d\n", ans);
	return 0;
}

