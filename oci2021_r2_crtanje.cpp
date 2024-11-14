#include <stdio.h>
#include <string.h>
 
#define N	100
 
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
 
int main() {
	static char cc[N + 1], aa[N + 1][N + 1];
	int n, i, x, mn, mx;
 
	scanf("%d%s", &n, cc);
	x = mn = mx = 0;
	for (i = 0; i < n; i++)
		if (cc[i] == '+')
			mx = max(mx, ++x);
		else if (cc[i] == '-')
			mn = min(mn, --x);
		else
			mx = max(mx, x + 1);
	x = 0;
	for (i = 0; i < mx - mn; i++)
		memset(aa[i], '.', n * sizeof *aa[i]);
	for (i = 0; i < n; i++)
		if (cc[i] == '+')
			aa[mx - ++x][i] = '/';
		else if (cc[i] == '-')
			aa[mx - x--][i] = '\\';
		else
			aa[mx - (x + 1)][i] = '_';
	for (i = 0; i < mx - mn; i++)
		printf("%s\n", aa[i]);
	return 0;
}

