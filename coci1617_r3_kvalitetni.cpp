#include <stdio.h>
#include <string.h>
 
#define N	1000000
#define K	50
 
double min(double a, double b) { return a < b ? a : b; }
 
unsigned int X = 12345;
 
int rand_() {
	return (X *= 3) >> 1;
}
 
void sort(double *aa, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r;
		double a = aa[l + rand_() % (r - l)], tmp;
 
		while (j < k)
			if (aa[j] == a)
				j++;
			else if (aa[j] < a) {
				tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = aa[j], aa[j] = aa[k], aa[k] = tmp;
			}
		sort(aa, l, i);
		l = k;
	}
}
 
char cc[N + 1]; int zz[K + 1];
 
double solve(char *cc, int n, int *j_) {
	double aa[K];
	int h, i, j, k, add;
	double sum, prod;
 
	if (cc[1] == '?') {
		*j_ = 3;
		return zz[1];
	}
	add = -1;
	for (i = 1, k = 0; i < n && cc[i] == '('; i += j + 1) {
		aa[k++] = solve(cc + i, n - i, &j);
		if (add == -1)
			add = cc[i + j] == '+';
	}
	*j_ = i;
	if (add == 1) {
		sum = 0;
		for (h = 0; h < k; h++)
			sum += aa[h];
		return min(sum, zz[k]);
	} else {
		sort(aa, 0, k);
		sum = 0, prod = 1;
		for (h = 0; h < k; h++) {
			if (sum + aa[h] * (k - h) >= zz[k]) {
				double a = (double) (zz[k] - sum) / (k - h);
 
				while (h < k)
					prod *= a, h++;
				return prod;
			}
			sum += aa[h], prod *= aa[h];
		}
		return prod;
	}
}
 
int main() {
	int n, k, h;
 
	scanf("%d", &k);
	for (h = 1; h <= k; h++)
		scanf("%d", &zz[h]);
	scanf("%s", cc), n = strlen(cc);
	printf("%.6f\n", solve(cc, n, &h));
	return 0;
}

