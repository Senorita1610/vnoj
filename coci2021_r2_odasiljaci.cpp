#include <math.h>
#include <stdio.h>
#include <string.h>
 
#define N	1000
#define INF	0x3f3f3f3f3f3f3f3fLL
 
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
 
int main() {
	static int xx[N], yy[N];
	static long long dd[N];
	int n, m, i;
	long long ans;
 
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &xx[i], &yy[i]);
	ans = 0;
	memset(dd, 0x3f, n * sizeof *dd), dd[0] = 0;
	for (m = 1; m <= n; m++) {
		int i_ = -1;
 
		for (i = 0; i < n; i++)
			if (dd[i] != -1 && (i_ == -1 || dd[i_] > dd[i]))
				i_ = i;
		ans = max(ans, dd[i_]);
		dd[i_] = -1;
		for (i = 0; i < n; i++)
			dd[i] = min(dd[i], (long long) (xx[i] - xx[i_]) * (xx[i] - xx[i_]) + (long long) (yy[i] - yy[i_]) * (yy[i] - yy[i_]));
	}
	printf("%f\n", sqrt(ans) / 2);
	return 0;
}

