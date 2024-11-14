#include<bits/stdc++.h>
using namespace std;
int t, n, m, a[10005][2], b[10000][2];
bool check(int x) {
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i][0] <= x) {
			sum += (x - a[i][0]) / a[i][1] + 1;
		}
	}
	for(int j = 1; j <= m; j++) {
		if(b[j][0] <= t - x) {
			sum -= (t - x - b[j][0]) / b[j][1] + 1;
		}
	}
	return sum > 0;
}
int main() {
	cin >> t >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> b[i][0] >> b[i][1];
	}
	int l = 1, r = t;
	while(l + 1 <r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	cout << l;
	return 0;
}

