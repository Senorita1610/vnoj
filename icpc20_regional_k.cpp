#include<bits/stdc++.h>
using namespace std;
const int N=2e3+4;
const double inf=1e15;
double dp[7][N];
double dis[N][N];
int st,n;
int check(int x){
	return (x+st<=n?x+st:x+st-n);
}
void dnc(int K,int L,int R,int OptL,int OptR){
	if(L>R) return;
	int mid=(L+R)/2;
	int optNow=OptL;
	dp[K][mid]=-inf;
	int m2=check(mid);
	for(int i=OptL;i<=min(OptR,mid-1);i++){
		double tmp=dp[K-1][i]+dis[check(i)][m2];
		if(tmp>=dp[K][mid]){
			dp[K][mid]=tmp,optNow=i;
		}
	}
	dnc(K,L,mid-1,OptL,optNow);
	dnc(K,mid+1,R,optNow,OptR);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<int,int>>v(n);
	for(auto &[x,y]:v) cin>>x>>y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=hypot(v[i-1].first-v[j-1].first,v[i-1].second-v[j-1].second);
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++) dp[0][i]=-inf;
	for(int i=1;i<=n;i++){
		st=i;
		for(int j=1;j<=5;j++) dnc(j,0,n-1,0,n-1);
		double res=0;
		for(int j=5;j<n;j++){
			res=max(res,dp[5][j]+dis[i][check(j)]);
		}
		cout<<fixed<<setprecision(10)<<res<<endl;
	}
}

