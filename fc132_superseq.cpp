#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=500;
int n,res;
int a[N+5];
long long base=1e9+1,mod=1e9+7;
long long hashh[M+5],sum[N+5];
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y%2==1) ans=(ans*x)%mod;
	return ans;
}
void prep() {
	for (int i=1;i<=M;i++) {
		long long val=i*power(base,i)%mod;
		hashh[i]=(hashh[i-1]+val)%mod;
	}
	for (int i=1;i<=n;i++) {
		long long val=power(base,a[i])%mod;
		sum[i]=(sum[i-1]+val)%mod;
	}
}
void calc(int m) {
	int len=m*(m+1)/2;
	for (int l=1;l+len-1<=n;l++) {
		int r=l+len-1;
		long long temp=(sum[r]-sum[l-1]%mod+mod)%mod;
		if (temp==hashh[m]) res++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    prep();
    for (int i=1;i<=n,i*(i+1)/2<=n;i++) calc(i);
    cout<<res;
}

