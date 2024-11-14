#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int g,h;cin >> g >> h;
	int kat = 1 , k = 0;
	while(kat <= g){
		kat *= h;
		k++;
	}
	int b = g * ((kat + g - 1) / g);
	int a = h * b + g;
	cout << a << " " << b << endl;
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int testcase = 1;cin >> testcase;
	while(testcase--)solve();
}

