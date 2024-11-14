#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, l, c[N];
int f() {
	sort(c + 1, c + n + 1);
	int h = -1;
	for(int i = n; i >= 1; i--) 
		h = max(h, min(c[i], n - i + 1)); 
	return h;
} 
signed main() {
	cin>>n>>l;
	for(int i = 1; i <= n; i++) cin>>c[i];
	int h = f(), p = lower_bound(c + 1, c + n + 1, h) - c, ll = l;
	for(int i = p; ll; ll--) {
		if(c[i] == c[p] && ll != l) break;	
		c[i]++, i++;
	}
	h = f(), l = ll;
	for(int i = h - 1; i >= 0 && ll; i--) {
		p = lower_bound(c + 1, c + n + 1, i) - c;
		for(int j = p; ll; ll--) {
			if(c[j] == c[p] && ll != l) break;
			c[j]++, j++;
		}
	}
	cout<<f()<<endl;
	return 0;
}

