#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
long long a[N+5],sum[N+5],mn[N+5],mx[N+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    }	
    mn[k-1]=LLONG_MAX;
    mx[k-1]=LLONG_MIN;
    for (int i=k;i<=n;i++) {
    	mn[i]=min(mn[i-1],sum[i]-sum[i-k]);
    	mx[i]=max(mx[i-1],sum[i]-sum[i-k]);
    }
    for (int i=k+1;i<=n-k+1;i++) {
    	res=max({res,abs(mx[i-1]-(sum[i+k-1]-sum[i-1])),abs(mn[i-1]-(sum[i+k-1]-sum[i-1]))});
    }
    cout<<res;
}

