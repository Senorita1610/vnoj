#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD = 1e9+7;
#define M 200010
#define SHA 200000
#define N 3010
#define PII pair<int,int>
int h,w,n;
int dp[N];
PII pos[N];
int jc[M];
int ny[M];
int ksm(int x,int b){
	int res=1;
	while(b){
		if(b&1){
			res=res*x%MOD;
		}
		x=x*x%MOD;
		b>>=1;
	}
	return res;
}
int getC(int na,int ma){
	return (jc[na]*ny[na-ma]%MOD)*ny[ma]%MOD;
}
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	cin>>h>>w>>n;
	jc[0]=1;
	ny[0]=1;
	jc[1]=1;
	for(int i=2;i<=SHA;i++) jc[i]=jc[i-1]*i%MOD;
	ny[SHA]=ksm(jc[SHA],MOD-2);
	for(int i=SHA-1;i>=1;i--) ny[i]=ny[i+1]*(i+1)%MOD;
	for(int i=1;i<=n;i++){
		cin>>pos[i].first>>pos[i].second;
	}
	pos[++n]=make_pair(h,w);
	sort(pos+1,pos+1+n);
	for(int i=1;i<=n;i++){
		dp[i]=getC(pos[i].first+pos[i].second-2,pos[i].first-1);
		for(int j=1;j<i;j++){
			if(pos[i].second>=pos[j].second){
				dp[i]=(dp[i]-dp[j]*getC(pos[i].first-pos[j].first+pos[i].second-pos[j].second,pos[i].first-pos[j].first))%MOD;
			}
		}
	}
	cout<<(dp[n]+MOD)%MOD;
	return 0;
}

