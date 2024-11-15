#include<iostream>
#include<cstring>
using namespace std;
const int N=1e4+5,T=1e2+5,mod=1e9+7;
long long ans;
int n,d,a[N],sum[N],dp[N][T];
string s;
int main(){
	cin>>s;
	cin>>d;
	n=s.length();
	for(int i=0;i<n;i++) a[i+1]=s[i]-'0';
	dp[0][0]=1;
	for(int i=0;i<=9;i++) dp[1][i%d]++;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<d;k++) dp[i+1][(j+k)>=d?((j+k)%d):(j+k)]=(dp[i+1][(j+k)>=d?((j+k)%d):(j+k)]+dp[i][k])%mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			ans+=dp[n-i][(-sum[i-1]-j%d+d*2)%d];
			if(ans>=mod) ans-=mod;
		}
		sum[i]=(sum[i-1]+a[i]);
		if(sum[i]>=d) sum[i]-=d;
	}
	cout<<(ans-1+mod+(sum[n]%d==0))%mod<<endl;
	return 0;
}

