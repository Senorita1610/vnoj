#include <bits/stdc++.h>

using namespace std;

const int N = 1000000 + 1;

int n, m, q, a[N], k;
int st[N], top, bot, f[N];

bool cmp(int i, int j) {
    if (f[i] != f[j]) return f[i] > f[j];
    return a[i] <= a[j];
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
    scanf("%d", &q);
    while (q) {
        q--;
        scanf("%d", &k);
        top = bot = 1;
        f[1] = 0;
        st[top] = 1;
        for(int i = 2; i <= n; i++) {
            int j = st[bot];
            if (a[i] >= a[j]) f[i] = f[j] + 1;
            else f[i] = f[j];
            while (bot <= top && cmp(st[top], i)) top--;
            st[++top] = i;
            j = i - k;
            while (bot <= top && st[bot] <= j) bot++;
        }
        //for(int i = 1; i <= n; i++) cout << f[i] << ' '; cout << "\n";
        printf("%d\n", f[n]);
    }
}

