#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,t,u,k;
long long a[N+5],cal[N+5],mod=1e9+7;
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	if (y==0) return 1;
	long long k=power(x,y/2);
	k*=k;
	k%=mod;
	if (y%2==1) k=(k*x)%mod;
	return k;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	cal[0]=1;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		cal[i]=cal[i-1]*a[i];
		cal[i]%=mod;
	}
	cin>>t;
	while (t--) {
		cin>>u>>k;
		int v=u+k-1;
		long long x=cal[u-1],y=cal[v];
		cout<<(y*power(x,mod-2))%mod<<'\n';
	}
}

