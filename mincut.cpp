#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int m,n,k;
long long a[N+5][N+5],sum[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++) {
    	for (int j=1;j<=n;j++) {
    		cin>>a[i][j];
    		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    	}
    }
    while (k--) {
    	int u,v,x,y;
    	cin>>u>>v>>x>>y;
    	int lo=u,hi=x-1;
    	long long t=sum[x][y]-sum[u-1][y]-sum[x][v-1]+sum[u-1][v-1],res=t;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		long long s=sum[mid][y]-sum[u-1][y]-sum[mid][v-1]+sum[u-1][v-1];
    		res=min(res,abs((t-s)-s));
    		if (s<t/2) lo=mid+1;
    		else hi=mid-1;
    	}
    	lo=v,hi=y-1;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		long long s=sum[x][mid]-sum[u-1][mid]-sum[x][v-1]+sum[u-1][v-1];
    		res=min(res,abs((t-s)-s));
    		if (s<t/2) lo=mid+1;
    		else hi=mid-1;
    	}
    	cout<<res<<'\n';
    }
}

