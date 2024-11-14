#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
struct str{
	string s;
	bool operator < (const str other) const{
		return s < other.s;
	};
};
 
void solve(){
	
	int n,m,pos;
	cin >> n >> m;
 
	vector<pair<pair<int,int>,str>> v(n);	
	for(int i = 0; i < n; i++){
		cin >> v[i].ss.s;
		for(int j = 0; j < m; j++){
			string q; cin >> q;
			if(q[0] == '-'){
				continue;
			}
			--v[i].ff.ff; v[i].ff.ss += 20 * (q[1] - '0') * 60;
			v[i].ff.ss += (q[4] - '0') * 3600 + 10 * (q[6] - '0') * 60 + (q[7] - '0') * 60;
			v[i].ff.ss += (q[9] - '0') * 10 + (q[10] - '0');
				
		}
		if(v[i].ss.s == "NijeZivotJedanACM"){
			pos = i;
		}
	}
 
	string fuck; cin >> fuck;
	v[pos].ff.ff = v[pos].ff.ss = 0;
	for(int i = 0; i < m; i++){
		string q; cin >> q;
		if(q[0] == '-'){
			continue;
		}
		--v[pos].ff.ff; v[pos].ff.ss += 20 * (q[1] - '0') * 60;
		v[pos].ff.ss += (q[4] - '0') * 3600 + 10 * (q[6] - '0') * 60 + (q[7] - '0') * 60;
		v[pos].ff.ss += (q[9] - '0') * 10 + (q[10] - '0');
	}
 
	sort(v.begin(),v.end());
	for(int i = 0; i < n; i++){
		if(v[i].ss.s == "NijeZivotJedanACM"){
			cout << i + 1 << endl;
		}	
	}
}
 
signed main(){ 
 
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t = 1;
//	cin >> t;
 
	while(t--)
		solve();
 	
	return 0;
}

