#include<bits/stdc++.h>

using namespace std;
int n, d, c[2005];
int posb[2005];
int solve(vector<int> a, vector<int> b){
	memset(posb,0,sizeof(posb));
	for (int i = 0; i < b.size(); i++){
		posb[b[i]] = i+1;
	}
	vector<int> vec;
	for (int i = 0; i < a.size(); i++){
		vector<int> cur;
		for (int j = a[i]-d; j <= a[i]+d; j++) if (j>0&&j<=2*n&&posb[j]){
			cur.push_back(posb[j]);
		}
		sort(cur.begin(),cur.end());
		reverse(cur.begin(),cur.end());
		for (int x: cur) vec.push_back(x);
	}
	int res = 0;
	vector<int> lis(2*n+1,1e9);
	lis[0] = -1e9;
	for (int i = 0; i < vec.size(); i++){
		int pos = lower_bound(lis.begin(),lis.end(),vec[i])-lis.begin();
		res = max(res,pos);
		lis[pos] = vec[i];
	}
	return res;
}

int main(){
	cin >> n >> d;
	int res = 0;
	for (int i = 1; i <= 2*n; i++) cin >> c[i];
	for (int i = 1; i <= 2*n; i++){
		vector<int> a, b;
		for (int j = 1; j < i; j++) a.push_back(c[j]);
		for (int j = i; j <= 2*n; j++) b.push_back(c[j]);
		res = max(res,solve(a,b));
	}
	cout << res;
	
	return 0;
}

