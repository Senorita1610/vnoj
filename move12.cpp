#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, c[100005], t[100005];
bool check(int x){
	vector<ii> v;
	for (int i = 1; i <= n; i++) v.push_back({c[i]-x/t[i],c[i]+x/t[i]});
	sort(v.begin(),v.end());
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 1, j = 0; i <= n; i++){
		while (j<n&&v[j].first<=i) pq.push(v[j++].second);
		while (pq.size()&&pq.top()<i) pq.pop();
		if (pq.empty()) return 0;
		pq.pop();
	}
	return 1;
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c[i] >> t[i];
	}
	int l = 0, h = 1e9, m, res;
	while (l<=h){
		m = l+h>>1;
		if (check(m)){
			res = m;
			h = m-1;
		} else l = m+1;
	}
	
	cout << res;
	
	return 0;
}

