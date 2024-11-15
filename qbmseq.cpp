#include<bits/stdc++.h>

using namespace std;
int n, a[10005], f[10005];
map<int,int> mp;
int main(){
	
	for (int i = 1, s = 0; s <= 1e8; i++){
		s += i;
		mp[s] = 1;
	}
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int res = 0;
	for (int i = 1, j = 1; i <= n;){
		if (!mp.count(a[i])){
			i++;
			continue;
		}
		j = i+1;
		while (a[j]>=a[j-1]&&mp.count(a[j])) j++;
		res = max(res,j-i);
		i = j;
	}
	cout << res;
	
	
	return 0;
}

