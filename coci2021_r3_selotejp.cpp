#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define N	1000
#define M	10
#define N_	(N * M)
 
int n_, nu, nv;
 
int *ev[1 + N_], eo[1 + N_];
 
void append(int u, int v) {
	int o = eo[u]++;
 
	if (o >= 2 && (o & o - 1) == 0)
		ev[u] = (int *) realloc(ev[u], o * 2 * sizeof *ev[u]);
	ev[u][o] = v;
}
 
int vv[1 + N_], uu[1 + N_], dd[1 + N_];
 
int bfs() {
	static int qu[1 + N_];
	int u, head, cnt;
 
	for (u = 0; u <= nu; u++)
		dd[u] = nu;
	head = cnt = 0;
	for (u = 1; u <= nu; u++)
		if (vv[u] == 0)
			dd[u] = 0, qu[head + cnt++] = u;
	while (cnt) {
		int d, o;
 
		u = qu[cnt--, head++], d = dd[u] + 1;
		for (o = eo[u]; o--; ) {
			int v = ev[u][o], w = uu[v];
 
			if (dd[w] == nu) {
				dd[w] = d;
				if (w == 0)
					return 1;
				qu[head + cnt++] = w;
			}
		}
	}
	return 0;
}
 
int eo_[1 + N_];
 
int dfs(int u) {
	int d, o;
 
	if (u == 0)
		return 1;
	d = dd[u] + 1;
	for (o = eo_[u]; o--; ) {
		int v = ev[u][o], w = uu[v];
 
		if (dd[w] == d && dfs(w)) {
			vv[u] = v, uu[v] = u;
			eo_[u] = o + 1;
			return 1;
		}
	}
	dd[u] = nu, eo_[u] = 0;
	return 0;
}
 
int hopcroft_karp() {
	int u, cnt;
 
	cnt = 0;
	while (bfs()) {
		memcpy(eo_, eo, (1 + nu) * sizeof *eo);
		for (u = 1; u <= nu; u++)
			if (vv[u] == 0 && dfs(u))
				cnt++;
	}
	return cnt;
}
 
int main() {
	static char cc[N][M + 1];
	static int uu_[N][M], vv_[N][M];
	int n, m, i, j, u;
 
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", cc[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			uu_[i][j] = vv_[i][j] = -1;
			if (cc[i][j] == '#') {
				n_++;
				if (i > 0 && cc[i - 1][j] == '#')
					uu_[i][j] = ++nu;
				if (j > 0 && cc[i][j - 1] == '#')
					vv_[i][j] = ++nv;
			}
		}
	for (u = 1; u <= nu; u++)
		ev[u] = (int *) malloc(2 * sizeof *ev[u]);
	for (i = 1; i < n; i++)
		for (j = 1; j < m; j++) {
			if (uu_[i][j] != -1 && vv_[i][j] != -1)
				append(uu_[i][j], vv_[i][j]);
			if (uu_[i][j] != -1 && vv_[i - 1][j] != -1)
				append(uu_[i][j], vv_[i - 1][j]);
			if (uu_[i][j - 1] != -1 && vv_[i][j] != -1)
				append(uu_[i][j - 1], vv_[i][j]);
			if (uu_[i][j - 1] != -1 && vv_[i - 1][j] != -1)
				append(uu_[i][j - 1], vv_[i - 1][j]);
		}
	printf("%d\n", n_ - (nu + nv - hopcroft_karp()));
	return 0;
}

