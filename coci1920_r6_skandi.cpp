#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define N	500
#define M	500
#define NU	(N * M)
#define NV	(N * M)
 
int *ev[1 + NU], eo[1 + NU];
 
void append(int u, int v) {
	int o = eo[u]++;
 
	if (o >= 2 && (o & o - 1) == 0)
		ev[u] = (int *) realloc(ev[u], o * 2 * sizeof *ev[u]);
	ev[u][o] = v;
}
 
int vv[1 + NU], uu[1 + NV], dd[1 + NU], nu, nv;
 
int bfs() {
	static int qu[NU];
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
 
int eo_[1 + NU];
 
int dfs(int u) {
	int o, d;
 
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
	eo_[u] = 0;
	return 0;
}
 
int hopcroft_karp() {
	int u, cnt = 0;
 
	while (bfs()) {
		memcpy(eo_, eo, (1 + nu) * sizeof *eo);
		for (u = 1; u <= nu; u++)
			if (vv[u] == 0 && dfs(u))
				cnt++;
	}
	return cnt;
}
 
int main() {
	static char cc[N][M + 1], inu[1 + NU], inv[1 + NV];
	static int uu_[N][M], vv_[N][M];
	int n, m, i, j, u, v, o;
 
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", cc[i]);
	nu = 0;
	for (i = 1; i < n; i++)
		for (j = 1; j < m; j++)
			if (cc[i][j] == '0') {
				if (cc[i][j - 1] == '1')
					nu++;
				uu_[i][j] = nu;
			}
	nv = 0;
	for (j = 1; j < m; j++)
		for (i = 1; i < n; i++)
			if (cc[i][j] == '0') {
				if (cc[i - 1][j] == '1')
					nv++;
				vv_[i][j] = nv;
			}
	for (u = 1; u <= nu; u++)
		ev[u] = (int *) malloc(2 * sizeof *ev[u]);
	for (i = 1; i < n; i++)
		for (j = 1; j < m; j++)
			if (cc[i][j] == '0')
				append(uu_[i][j], vv_[i][j]);
	printf("%d\n", hopcroft_karp());
	for (u = 1; u <= nu; u++)
		if (dd[u] == nu)
			inu[u] = 1;
		else
			for (o = eo[u]; o--; ) {
				v = ev[u][o];
				inv[v] = 1;
			}
	for (i = 1; i < n; i++)
		for (j = 1; j < m; j++)
			if (cc[i][j] == '0' && cc[i][j - 1] == '1' && inu[uu_[i][j]])
				printf("%d %d DESNO\n", i + 1, j);
	for (j = 1; j < m; j++)
		for (i = 1; i < n; i++)
			if (cc[i][j] == '0' && cc[i - 1][j] == '1' && inv[vv_[i][j]])
				printf("%d %d DOLJE\n", i, j + 1);
	return 0;
}

