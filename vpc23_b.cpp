#include                    <bits/stdc++.h>
using                       namespace std;
#define fi                  first
#define se                  second
#define pb(x)               push_back(x)
#define endl                cout<<"\n";
#define int               long long
typedef pair<int, int>      ii;
typedef vector<int>         vi;
typedef long double         ldb;
const string F =            "sample";
const string IF =           F + ".inp";
const string OF =           F + ".out";
const ldb PI =              3.14159265358979;
const int maxN =            1e6;
const int mod  =            1e9 + 7;
void opf(bool c){           if (c == 1){	
freopen(IF.c_str(),         "r", stdin);
freopen(OF.c_str(),         "w", stdout);}}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	opf(0);
	int T;
	cin >> T;
	while (T--){
		int c, m, n;
		cin >> c >> m >> n;
		vector<pair<int, int>> v;
		for (int i=1; i<=m; i++){
			int x;
			cin >> x;
			v.push_back({x, -1});
		}
		
		for (int i=1; i<=n; i++){
			int x, y;
			cin >> x >> y;
			v.push_back({x, y});
		}
		sort(v.begin(), v.end());
		int cur_w = c, ans = 0;
		for (auto x : v){
			if (x.se > 0){
				if (cur_w < x.se){
				}
				else{
					ans += x.se;
					cur_w -= x.se;
				}
			}
			else{
				cur_w = c;
			}
		}
		cout << ans << "\n";
	}
}

