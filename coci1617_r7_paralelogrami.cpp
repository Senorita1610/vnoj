#include <stdio.h>
 
#define N	400
#define M	2500
 
int cross(int x0, int y0, int x1, int y1, int x2, int y2) {
	return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}
 
int main() {
	static int xx[N], yy[N], ii[M], jj[M], kk[M];
	int n, m, h, i, j, k, l, done, tmp, x1, y1, x2, y2, z;
 
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &xx[i], &yy[i]);
	done = 1;
	for (i = 0; i < n; i++)
		if (xx[i] < 0 || yy[i] < 0) {
			done = 0;
			break;
		}
	if (done) {
		printf("0\n");
		return 0;
	}
	i = 0, j = 1;
	for (k = 2; k < n; k++)
		if (cross(xx[0], yy[0], xx[1], yy[1], xx[k], yy[k]) != 0)
			break;
	if (k == n) {
		printf("-1\n");
		return 0;
	}
	if (xx[i] - yy[i] > xx[j] - yy[j])
		tmp = i, i = j, j = tmp;
	if (xx[i] - yy[i] > xx[k] - yy[k])
		tmp = i, i = k, k = tmp;
	if (xx[j] - yy[j] > xx[k] - yy[k])
		tmp = j, j = k, k = tmp;
	tmp = j, j = i, i = tmp;
	if (cross(xx[i], yy[i], xx[j], yy[j], xx[k], yy[k]) < 0)
		tmp = j, j = k, k = tmp;
	x1 = xx[j] - xx[i], y1 = yy[j] - yy[i], x2 = xx[k] - xx[i], y2 = yy[k] - yy[i];
	m = 0;
	for (h = 0; h < 20; h++) {
		for (z = 0; z < y2 - x2; z++) {
			ii[m] = j, jj[m] = k, kk[m] = i, m++;
			ii[m] = i, jj[m] = j, kk[m] = k, m++;
			tmp = i, i = j, j = k, k = tmp;
		}
		for (z = 0; z < x2 - y2; z++) {
			ii[m] = i, jj[m] = k, kk[m] = j, m++;
			ii[m] = j, jj[m] = i, kk[m] = k, m++;
			tmp = j, j = i, i = k, k = tmp;
		}
		for (z = 0; z < x1 - y1; z++) {
			ii[m] = k, jj[m] = j, kk[m] = i, m++;
			ii[m] = i, jj[m] = k, kk[m] = j, m++;
			tmp = i, i = k, k = j, j = tmp;
		}
		for (z = 0; z < y1 - x1; z++) {
			ii[m] = i, jj[m] = j, kk[m] = k, m++;
			ii[m] = k, jj[m] = i, kk[m] = j, m++;
			tmp = k, k = i, i = j, j = tmp;
		}
	}
	for (l = 0; l < n; l++)
		if (l != i && l != j && l != k)
			ii[m] = i, jj[m] = j, kk[m] = l, m++;
	printf("%d\n", m);
	for (h = 0; h < m; h++)
		printf("%d %d %d\n", ii[h] + 1, jj[h] + 1, kk[h] + 1);
	return 0;
}

