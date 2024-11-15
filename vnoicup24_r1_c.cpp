#include<bits/stdc++.h>

using namespace std;
int x;
void solve(){
	cin >> x;
	if (x==1){
		cout << "1\n1\n";
		return;
	}
	int base = 1, cnt = 0;
	while (base-2<=x) base *= 2, cnt++;
	base /= 2;
	cnt--;
	cout << cnt << "\n";
	int tmp = base-1;
	for (int i = 0; i < cnt; i++){
		int v = tmp^(1<<i);
		cout << v << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

