#include <bits/stdc++.h>
using namespace std;
#define sp " "
#define endl "\n";
#define fastio() cin.tie(0), ios_base::sync_with_stdio(0)
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define N 1000005
 
const int modulo = 1e9 + 7;
 
int cnt[N], res[N], arr[N];
 
int32_t main()
{
	fastio();
 
	int n, k;
	cin>>n>>k;
 
	for (int i = 1; i <= n; i++){
		cin>>arr[i];
		cnt[arr[i]]++;
	}
 
	for (int i = k + 1; i < N; i++){
		for (int j = 0; j < N; j += i)
			res[j] += cnt[i];
	}
 
	for (int i = 1; i <= n; i++){
		if (arr[i] < k) cout<<0<<sp;
		else cout<<res[arr[i] - k] - (k == 0 ? 1 : 0)<<sp;
	}
 
	cout<<endl;
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " seconds\n";
}

