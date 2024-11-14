#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define trav(a,x) for(auto& a:x)
#define FOR(i,a,b) for(int i=a;i<=(signed)(b);i++)
#define ROF(i,a,b) for(int i=a;i>=(signed)(b);i--)
#define FOR(i,a) for(int i=0;i<(signed)(a);i++)
#define vi vector<int>
#define f first
#define s second
#define all(v) v.begin(),v.end()
typedef long long ll;
const ll mod=1e9+7,MOD=998244353;
double dp[305][305][305];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int>cnt(4);
	FOR(i,n){
		int u;
		cin>>u;
		cnt[u]++;
	}
	for(int i=0;i<=cnt[3];i++){
		for(int j=0;j<=cnt[2]+cnt[3];j++){
			for(int k=0;k<=cnt[1]+cnt[2]+cnt[3];k++){
				if(i==j&&j==k&&k==0) continue;
				if(i+j+k>n) continue;
				dp[i][j][k]=n*1.0/(i+j+k);
				if(k>0) dp[i][j][k]+=(k*1.0/(i+j+k))*dp[i][j][k-1];
				if(j>0) dp[i][j][k]+=(j*1.0/(i+j+k))*dp[i][j-1][k+1];
				if(i>0) dp[i][j][k]+=(i*1.0/(i+j+k))*dp[i-1][j+1][k];
			}
		}
	}
	cout<<setprecision(15)<<dp[cnt[3]][cnt[2]][cnt[1]];
	return 0;
}

