#include <bits/stdc++.h>

using namespace std;

const int N = 50000 + 1;

int n, t[N], vmax;
long long m, f[N];

void update(int i, int x) {
    for(i; i <= n; i += i & (-i)) t[i] += x;
}

int find(int k) {
    int res = 0, sum = 0;
    for(int i = vmax; i >= 0; i--) if (res + (1 << i) <= n && sum + t[res + (1 << i)] <= k) {
        res += 1 << i;
        sum += t[res];
    }
    return res;
}

int get(int i) {
	int res = 0;
	for(i; i; i -= i & (-i)) res += t[i];
	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    f[0] = 0;
    for(int i = 1; i < N; i++) f[i] = (long long)i * (i-1) / 2;
    for(int i = 1; i < N; i++) update(i, 1);
    while (1) {
        cin >> n >> m;
        if (n < 0) break;
        memset(t, 0, sizeof t);
        vmax = trunc(log(n) / log(2));
        for(int i = 1; i <= n; i++) update(i, 1);
        for(int i = 1; i <= n; i++) {
            int k = max(m - f[n-i] + 1, 1LL);
            int j = find(k-1) + 1;
            cout << j << ' ';
            update(j, -1);
            m -= get(j);
        }
        cout << "\n";
    }
}

