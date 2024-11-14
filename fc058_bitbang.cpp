#include <stdio.h>
#include <string.h>
 
#define N	200000
 
int main() {
	int t;
 
	scanf("%d", &t);
	while (t--) {
		static char cc[N + 1];
		int n, l, i, j, dies;
 
		scanf("%s", cc), n = strlen(cc);
		l = 0;
		while ((n + 1 & 1 << l) == 0)
			l++;
		dies = 1;
		for (i = (1 << l) - 1; i < n; i += 1 << l) {
			if (cc[i] != '0') {
				dies = 0;
				break;
			}
			for (j = 1; j < 1 << l; j++)
				if (cc[i - j] != cc[i + j]) {
					dies = 0;
					break;
				}
		}
		printf(dies ? "NO\n" : "YES\n");
	}
	return 0;
}

