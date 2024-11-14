#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
long long l,r,a[N+5];
long long concat(long long x,long long y) {
	long long z=y;
	while (z>0) {
		z/=10;
		x*=10;
	}
	return x+y;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>l>>r;
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		long long res=0;
		for (int i=1;i<=n;i++) {
			int lo=1,hi=n,rl=-1,rr=-1;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				if (concat(a[i],a[mid])>=l) {
					rl=mid;
					hi=mid-1;
				} else lo=mid+1;
			}
			lo=1,hi=n;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				if (concat(a[i],a[mid])<=r) {
					rr=mid;
					lo=mid+1;
				} else hi=mid-1;
			}
			if (rr!=-1&&rl!=-1) res+=rr-rl+1;
		}
		cout<<res<<'\n';
	}
}

