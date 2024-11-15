#include<bits/stdc++.h>
using namespace std;
const int N=20,M=(1<<17)+5;
int a[N][N],n;
long long sum[M],dp[M];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int s=0,i;s<(1<<n);s++){
		i=__builtin_ctz(s);
		sum[s]=sum[s-(s&-s)];
		for(int j,m=s;m;m^=(m&-m)){
			j=__builtin_ctz(m);
			sum[s]+=a[i][j];
		}
		dp[i]=-1e11;
	}
	dp[0]=0;
	for(int s=0;s<(1<<n);s++){
		for(int m=s;m;m=((m-1)&s)){
			dp[s]=max(dp[s],dp[s^m]+sum[m]);
		}
	}
	cout<<dp[(1<<n)-1];
	return 0;
}

