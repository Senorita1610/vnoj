#include <stdio.h>
#include <string.h>
 
#define N	100000
#define M	N
 
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
 
unsigned int X = 12345;
 
int rand_() {
	return (X *= 3) >> 1;
}
 
int xx[N], yy[N];
int ii_[M * 2];
 
int compare_x(int i, int j) { return xx[i] - xx[j]; }
int compare_y(int i, int j) { return yy[i] - yy[j]; }
int compare_z(int h1, int h2) {
	return yy[ii_[h1]] != yy[ii_[h2]] ? yy[ii_[h1]] - yy[ii_[h2]] : yy[ii_[h2 ^ 1]] - yy[ii_[h1 ^ 1]];
}
 
int (*compare)(int, int);
 
void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;
 
		while (j < k) {
			int c = compare(ii[j], i_);
 
			if (c == 0)
				j++;
			else if (c < 0) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
			}
		}
		sort(ii, l, i);
		l = k;
	}
}
 
int ds[(M + 1) * 2];
 
int find(int i) {
	return ds[i] < 0 ? i : (ds[i] = find(ds[i]));
}
 
void join(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j)
		return;
	if (ds[i] > ds[j])
		ds[i] = j;
	else {
		if (ds[i] == ds[j])
			ds[i]--;
		ds[j] = i;
	}
}
 
int zz[1 + M * 4], ll[1 + M * 4], rr[1 + M * 4], hh[1 + M * 4], u_, l_, r_;
 
int node(int h) {
	static int _ = 1;
 
	zz[_] = rand_();
	hh[_] = h;
	return _++;
}
 
void split(int u, int h) {
	int c;
 
	if (u == 0) {
		u_ = l_ = r_ = 0;
		return;
	}
	c = xx[ii_[hh[u] << 1 | 0]] - xx[ii_[h << 1 | 0]];
	if (c < 0) {
		split(rr[u], h);
		rr[u] = l_, l_ = u;
	} else if (c > 0) {
		split(ll[u], h);
		ll[u] = r_, r_ = u;
	} else {
		u_ = u, l_ = ll[u], r_ = rr[u];
		ll[u] = rr[u] = 0;
	}
}
 
int merge(int u, int v) {
	if (u == 0)
		return v;
	if (v == 0)
		return u;
	if (zz[u] < zz[v]) {
		rr[u] = merge(rr[u], v);
		return u;
	} else {
		ll[v] = merge(u, ll[v]);
		return v;
	}
}
 
int first(int u) { return ll[u] == 0 ? (u == 0 ? -1 : hh[u]) : first(ll[u]); }
int last(int u) { return rr[u] == 0 ? (u == 0 ? -1 : hh[u]) : last(rr[u]); }
 
int tr_higher(int u, int x) {
	int h = -1;
 
	while (u)
		if (xx[ii_[hh[u] << 1 | 0]] > x)
			h = hh[u], u = ll[u];
		else
			u = rr[u];
	return h;
}
 
int main() {
	static int ii[N], dd[N], cc[M + 1], hh[M * 2], qq[M];
	int n, m, h, i, u1, u2;
 
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &xx[i], &yy[i]);
	for (i = 0; i < n; i++)
		ii[i] = i;
	m = 0;
	compare = compare_x, sort(ii, 0, n);
	for (i = 0; i < n; i++)
		if (i + 1 < n && xx[ii[i]] == xx[ii[i + 1]]) {
			ii_[m << 1 | 0] = ii[i], ii_[m << 1 | 1] = ii[i + 1], m++;
			dd[ii[i]]++, dd[ii[i + 1]]++;
		}
	compare = compare_y, sort(ii, 0, n);
	for (i = 0; i < n; i++)
		if (i + 1 < n && yy[ii[i]] == yy[ii[i + 1]]) {
			ii_[m << 1 | 0] = ii[i], ii_[m << 1 | 1] = ii[i + 1], m++;
			dd[ii[i]]++, dd[ii[i + 1]]++;
		}
	for (i = 0; i < n; i++)
		if (dd[i] == 0) {
			printf("NE\n");
			return 0;
		}
	for (h = 0; h < m * 2; h++)
		hh[h] = h;
	compare = compare_z, sort(hh, 0, m * 2);
	memset(ds, -1, (m + 1) * 2 * sizeof *ds);
	u1 = u2 = 0;
	for (h = 0; h < m * 2; h++) {
		int h_ = hh[h], h1 = h_ >> 1, p, q;
 
		if (yy[ii_[h_]] < yy[ii_[h_ ^ 1]]) {
			split(u1, h1), p = last(l_), q = first(r_), u1 = merge(merge(l_, node(h1)), r_);
			if (p != -1 && q != -1)
				split(u2, p), u2 = merge(l_, r_);
			if (p != -1)
				split(u2, p), u2 = merge(merge(l_, node(p)), r_);
			if (q != -1)
				split(u2, h1), u2 = merge(merge(l_, node(h1)), r_);
			qq[h1] = q;
			if (p != -1)
				qq[p] = h1;
		} else if (yy[ii_[h_]] > yy[ii_[h_ ^ 1]]) {
			split(u1, h1), p = last(l_), q = first(r_), u1 = merge(l_, r_);
			if (p != -1)
				split(u2, p), u2 = merge(l_, r_);
			if (q != -1)
				split(u2, h1), u2 = merge(l_, r_);
			if (p != -1 && q != -1)
				split(u2, p), u2 = merge(merge(l_, node(p)), r_);
			if (p != -1)
				qq[p] = q;
		} else if (xx[ii_[h_]] < xx[ii_[h_ ^ 1]]) {
			int l = xx[ii_[h_]], r = xx[ii_[h_ ^ 1]], h2, h3;
 
			h2 = tr_higher(u1, l - 1);
			if (h2 != -1 && xx[ii_[h2 << 1 | 0]] <= r) {
				join(h1 << 1 | 0, h2 << 1 | 1), join(h1 << 1 | 1, h2 << 1 | 0);
				while (1) {
					h2 = tr_higher(u2, l - 1);
					if (h2 == -1)
						break;
					h3 = qq[h2];
					if (xx[ii_[h3 << 1 | 0]] > r)
						break;
					join(h2 << 1 | 0, h3 << 1 | 0), join(h2 << 1 | 1, h3 << 1 | 1);
					split(u2, h2), u2 = merge(l_, r_);
				}
			}
		}
	}
	for (h = 0; h < m; h++)
		if (dd[ii_[h << 1 | 0]] == 1 || dd[ii_[h << 1 | 1]] == 1)
			join(h << 1 | 0, m << 1 | 1), join(h << 1 | 1, m << 1 | 0);
	for (h = 0; h < m; h++)
		if (find(h << 1 | 0) == find(h << 1 | 1)) {
			printf("NE\n");
			return 0;
		}
	for (h = 0; h <= m; h++)
		cc[h] = find(h << 1 | 0) < find(h << 1 | 1);
	if (cc[m])
		for (h = 0; h <= m; h++)
			if (find(h << 1 | 0) == find(m << 1 | 0) || find(h << 1 | 0) == find(m << 1 | 1))
				cc[h] ^= 1;
	printf("DA\n");
	for (h = 0; h < m; h++)
		if (cc[h])
			printf("%d %d\n", ii_[h << 1 | 0] + 1, ii_[h << 1 | 1] + 1);
	return 0;
}

