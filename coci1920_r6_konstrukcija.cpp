#include <stdio.h>
 
#define N	1000
#define M	1000
#define L	60
 
int main() {
	static int ii[M], jj[M];
	int m, i, l, a, b;
	long long k;
 
	scanf("%lld", &k);
	m = 0;
	for (a = 1; a <= 3; a++)
		ii[m] = a, jj[m] = N - 1, m++;
	for (l = 1; l < L; l++)
		for (a = 1; a <= 3; a++)
			for (b = 1; b <= 3; b++)
				ii[m] = l * 3 + a, jj[m] = (l - 1) * 3 + b, m++;
	for (b = 1; b <= 3; b++)
		ii[m] = 0, jj[m] = (L - 1) * 3 + b, m++;
	k += 1LL << L;
	i = N - 2;
	for (l = L; l >= 0; l -= 2)
		while (k >= 1LL << l) {
			ii[m] = 0, jj[m] = i, m++;
			if (l > 0)
				for (b = 1; b <= 3; b++)
					ii[m] = i, jj[m] = (l - 1) * 3 + b, m++;
			else
				ii[m] = i, jj[m] = N - 1, m++;
			i--, k -= 1LL << l;
		}
	printf("1000 %d\n", m);
	while (m--)
		printf("%d %d\n", ii[m] + 1, jj[m] + 1);
	return 0;
}

