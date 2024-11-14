#include<bits/stdc++.h>

using namespace std;
int n, m, k, a[405][405], cnt[30];
long long res;
string s[405];
int gett(int x, int y, int u, int v){
	return a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1];
}

int main(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = "#" + s[i];
		for (int j = 1; j <= m; j++) 
			a[i][j] = (s[i][j]=='z') + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
	}
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++){
		memset(cnt,0,sizeof(cnt));
		for (int l = 1, r = 1; r <= m; r++){
			cnt[s[i][r]-'a'] += s[i][r]==s[j][r];
			while (gett(i,l,j,r)>k){
				cnt[s[i][l]-'a'] -= s[i][l]==s[j][l];
				l++;
			};
			res += 1ll*(s[i][r]==s[j][r])*(cnt[s[i][r]-'a']);
		}
	}
	cout << res;
	
	
	return 0;
}

