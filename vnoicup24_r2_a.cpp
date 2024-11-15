#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int maxn = 1e6 + 5;
ll test, n, x, res, pos, a[maxn + 2];
bool ok = 0;
int main() {
    nothing
    cin >> test;
    while (test--) {
    	cin >> n >> x;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	sort(a + 1, a + 1 + n);
    	res = 0;
    	for (int i = 1; i <= n; ++i) {
    		pos = -1;
    		for (int j = n; j >= 1; --j) {
    			if (a[j] == -1) continue;
    			if (x * i >= a[j]) {
	                pos = j;
	                break;
	            }
    		}
    		if (pos == -1) break;
    		a[pos] = -1;
    		res++;
    	}
    	cout << res << endl;
    }
    return 0;
}

