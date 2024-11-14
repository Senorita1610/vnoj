#include<bits/stdc++.h>

using namespace std;
int n, m ;
long long f[2005][2005], e[2005], s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> e[i];
	memset(f,0x3f,sizeof(f));
	f[n+1][0] = 0;
	for (int i = n; i > 0; i--){
		for (int j = 0; j <= n; j++){
			f[i][j] = f[i+1][j];
			if (j) f[i][j] = min(f[i][j],max(f[i+1][j-1]-e[i],-e[i]));
			f[0][j] = min(f[0][j],f[i][j]);
		}
	}
	sort(f[0]+1,f[0]+n+1);
	while (m--){
		cin >> s;
		int pos = upper_bound(f[0]+1,f[0]+n+1,s)-f[0]-1;
		cout << pos << " ";
	}
	
	return 0;
}

