#include <stdio.h>
#include <string.h>
 
#define N	2000
#define M	2000
#define L	10
#define A	26
#define MD	1000000007
 
unsigned int X = 12345;
 
int rand_() {
	return (X *= 3) >> 1;
}
 
int vv[N + 1], ff[N + 1], gg[N + 1];
 
void init() {
	int i;
 
	ff[0] = gg[0] = 1;
	for (i = 1; i <= N; i++) {
		vv[i] = i == 1 ? 1 : (long long) vv[i - MD % i] * (MD / i + 1) % MD;
		ff[i] = (long long) ff[i - 1] * i % MD;
		gg[i] = (long long) gg[i - 1] * vv[i] % MD;
	}
}
 
int choose(int n, int k) {
	return (long long) ff[n] * gg[k] % MD * gg[n - k] % MD;
}
 
int kk[N][A];
 
void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;
 
		while (j < k) {
			int c = memcmp(kk[ii[j]], kk[i_], sizeof kk[i_]);
 
			if (c == 0)
				j++;
			else if (c < 0) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
			}
		}
		sort(ii, l, i);
		l = k;
	}
}
 
int main() {
	static int ii[N], dp[M + 1];
	int n, m, i, j, k, s, s_;
 
	init();
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		static char cc[L + 1];
		int l, h;
 
		scanf("%s", cc), l = strlen(cc);
		for (h = 0; h < l; h++)
			kk[i][cc[h] - 'a']++;
	}
	for (i = 0; i < n; i++)
		ii[i] = i;
	sort(ii, 0, n);
	dp[0] = 1;
	for (i = 0; i < n; i = j) {
		j = i + 1;
		while (j < n && memcmp(kk[ii[j]], kk[ii[i]], sizeof kk[ii[i]]) == 0)
			j++;
		for (s = m; s >= 0; s--) {
			int x = dp[s];
 
			dp[s] = 0;
			for (k = 0; k <= j - i && (s_ = s + k * (k - 1) / 2) <= m; k++)
				dp[s_] = (dp[s_] + (long long) x * choose(j - i, k)) % MD;
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}

