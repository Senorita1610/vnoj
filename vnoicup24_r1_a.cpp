#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int maxn = 1e6 + 5;
ll test, n, a[maxn + 2];
ll cnt[3] = {0, 0, 0};
int main() {
    nothing
    cin >> test;
    while (test--) {
    	cin >> n;
    	cnt[1] = cnt[2] = 0;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		if (a[i] == 1) cnt[1]++;
    		else cnt[2]++, cnt[1] += a[i] - 2;
    	}
    	cout << cnt[1] / 2 + cnt[2] / 2 << endl;
    }
    return 0;
}

