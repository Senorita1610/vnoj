#include<bits/stdc++.h>
using namespace std;
const int maxN = 55;
int n, a[maxN], b[maxN];
typedef pair<int,int> ii;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]] = i;
	}
	vector<ii> res;
	for (int i = 1; i <= n; i++){
		int pos = -1;
		for (int j = i; j <= n; j++) if (a[j]==i) pos = j;
		if (pos==i) continue;
		res.push_back({pos,n+1});
		for (int j = pos-1; j >= i; j--){
			res.push_back({j,j+1});
			swap(a[j],a[j+1]);
		}
		res.push_back({n+1,i});
	}
	cout << res.size() << "\n";
	for (auto it: res){
		cout << it.first << " " << it.second << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

