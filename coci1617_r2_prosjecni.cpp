#include <cstdio>
 
int N, A[101][101], K;
 
int main() {
	int i, j, s;
	scanf("%d", &N);
	if (N == 1) {
		puts("1");
		return 0;
	}
	else if (N == 2) {
		puts("-1");
		return 0;
	}
	K = N*(N - 1) / 2;
	for (i = 0; i < N-1; i++) {
		for (j = 0; j < N - 1; j++) A[i][j] = K*i + j + 1;
		A[i][N - 1] = K*(i + 1);
	}
	for (i = 0; i < N; i++) {
		for (j = 0, s = 0; j < N - 1; j++) s += A[j][i];
		A[N - 1][i] = A[N - 2][i] * N - s;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) printf("%d ", A[i][j]);
		puts("");
	}
	return 0;
}

