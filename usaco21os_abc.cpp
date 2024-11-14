#include <bits/stdc++.h>
using namespace std;

int t;
int n, x[8], a[8], ans, b[8];
int ji[1000005][3];

void dfs(int p) {
	if (p == n) {
		memcpy(b, a, sizeof(b));
		if (b[4]) {
			if (!b[1] && b[2]) b[1] = b[4] - b[2];
			if (!b[2] && b[1]) b[2] = b[4] - b[1];
			if (!b[3] && b[7]) b[3] = b[7] - b[4];
		}
		if (b[5]) {
			if (!b[2] && b[3]) b[2] = b[5] - b[3];
			if (!b[3] && b[2]) b[3] = b[5] - b[2];
			if (!b[1] && b[7]) b[1] = b[7] - b[5];
		}
		if (b[6]) {
			if (!b[1] && b[3]) b[1] = b[6] - b[3];
			if (!b[3] && b[1]) b[3] = b[6] - b[1];
			if (!b[2] && b[7]) b[2] = b[7] - b[6];
		}
		if (b[1] > 0 && b[1] <= b[2] && b[2] <= b[3]) {
			if (b[4] && b[4] != b[1] + b[2]) return;
			if (b[5] && b[5] != b[2] + b[3]) return;
			if (b[6] && b[6] != b[3] + b[1]) return;
			if (b[7] && b[7] != b[1] + b[2] + b[3]) return;
			for (int i = 1; i <= ans; ++i)
				if (ji[i][0] == b[1] && ji[i][1] == b[2] && ji[i][2] == b[3]) return;
			++ans;
			ji[ans][0] = b[1];
			ji[ans][1] = b[2];
			ji[ans][2] = b[3];
		}
		return;
	}
	for (int i = 1; i <= 7; ++i) {
		if (a[i]) continue;
		a[i] = x[p];
		dfs(p + 1);
		a[i] = 0;
	}
}

signed main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
		sort(x, x + n);
		memset(a, 0, sizeof(a));
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}

