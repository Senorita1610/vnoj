#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long x,y,a[N+5],f[N+5];
long long res=LLONG_MIN,l,r;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>x>>y;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int u=1;u<=n;u++) {
    	if (a[u]>=x) {
	    	int v=u;
	    	while (v<=n&&a[v]>=x) v++;
	    	v--;
	    	f[u-1]=0;
	    	int vt=u-1,j=u-1;
	    	for (int i=u;i<=v;i++) {
	    		f[i]=f[i-1]+a[i];
	    		if (a[u]>=x&&a[i]<=y) {
	    			while (j<i) {
	    				if (f[vt]>f[j]) vt=j;
	    				j++;
	    			}
	    		}
	    		if (j>=u&&res<f[i]-f[vt]) {
	    			res=f[i]-f[vt];
	    			l=vt+1;
	    			r=i;
	    		}
	    	}
	    	u=v;
    	}
    }
    cout<<res<<'\n'<<l<<' '<<r;
}

