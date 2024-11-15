#include<bits/stdc++.h>

using namespace std;
long long x, k, y;
void solve(){
	cin >> x >> k;
	long long g = __gcd(x,k);
	x /= g;
	k /= g;
	cout << k << "\n";

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}

