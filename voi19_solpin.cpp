#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int m,n,qu,u,v,s,t,x,y,p,q,type;
int a[N+5][N+5],sum[N+5][N+5];
void prep() {
	for (int i=m+1;i<=m*2;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=a[i-m][j];
	for (int i=1;i<=m;i++) 
		for (int j=n+1;j<=n*2;j++)
			a[i][j]=a[i][j-n];
	for (int i=m+1;i<=m*2;i++)
		for (int j=n+1;j<=n*2;j++)
			a[i][j]=a[i-m][j-n];
	for (int i=1;i<=m*2;i++) {
		for (int j=1;j<=n*2;j++) {
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>m>>n;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) 
			cin>>a[i][j];
	prep();
	cin>>qu;
	while (qu--) {
		cin>>type;
		if (type==0) {
			cin>>x>>y;
			p+=y;
			q+=x;
			p%=m;
			q%=n;
		} else {
			cin>>u>>v>>s>>t;
			u+=p,s+=p;
			v+=q,t+=q;
			cout<<sum[s][t]-sum[u-1][t]-sum[s][v-1]+sum[u-1][v-1]<<'\n';
		}
	}
}

