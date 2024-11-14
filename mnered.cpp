#include<bits/stdc++.h>
using namespace std;
int n, m, x, y, k[105][105], sum[105][105], ans=0x3f3f3f;
int main() {
	cin >> n >> m;
	for(int i=1; i<=m; i++) {
		cin >> x >> y;
		k[x][y]++;
	}
	for(int len1=1, len2; len1<=m; len1++) { 
		if(m%len1) continue;
		len2=m/len1;
		for(int x1=1; x1+len1-1<=n; x1++) {
			for(int y1=1; y1+len2-1<=n; y1++) {
				int t=0;
				for(int x=x1; x<=x1+len1-1; x++) {
					for(int y=y1; y<=y1+len2-1; y++) {
						if(!k[x][y]) t++;
					}
				}
				ans=min(ans, t);
			}
		}
	}
	cout << ans;
}

