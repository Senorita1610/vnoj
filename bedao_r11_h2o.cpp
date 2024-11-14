#include<bits/stdc++.h>


using namespace std;
int n, w[1000005], x[1000005];
long long int pref1[1000005], pref2[1000005];
int q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> w[i] >> x[i];
		pref1[i] = pref1[i-1]+x[i];
		pref2[i] = pref2[i-1]+1ll*x[i]*w[i];
	}
	cin >> q;
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << (pref1[r-1]-pref1[l-1])*w[r]-(pref2[r-1]-pref2[l-1]) << "\n";
	}
	
	return 0;
}

