#include <stdio.h>
 
#define N	200000
 
int main() {
	static char cc[N + 1];
	static int kk[4], ii[N];
	int n, i, x, cnt;
 
	scanf("%d%s", &n, cc);
	x = 0;
	for (i = 0; i < n; i++) {
		cc[i] -= '0';
		kk[(int) cc[i]]++;
		x ^= cc[i];
	}
	if (x != 0 || kk[1] == n || kk[2] == n || kk[3] == n) {
		printf("NE\n");
		return 0;
	}
	cnt = 0;
	ii[cnt++] = 0;
	printf("DA\n");
	for (i = 1; i < n; i++) {
		int a, b;
 
		while (cnt >= 2 && (a = cc[ii[cnt - 2]]) != (b = cc[ii[cnt - 1]]) && (kk[a] > 1 || kk[b] > 1)) {
			kk[a]--, kk[b]--, kk[a ^ b]++, cnt--;
			cc[ii[cnt - 1]] = a ^ b;
			printf("%d %d %d\n", ii[cnt - 1] + 1, i + 1, a ^ b);
		}
		ii[cnt++] = i;
	}
	return 0;
}

