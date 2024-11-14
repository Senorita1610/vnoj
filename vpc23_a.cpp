#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> a[i][j];
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (a[i][j] == '.' && a[i][j+1] == '.' && a[i][j+2] == '.'){
				cout << i << " " << j;
				return 0;
			}
		}
	}
}

