#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
typedef pair<int,int>pii;
typedef tuple<int,int,int>tii;
const int N=1e6+7;
const int M=1e9+7;
ll n,k;
ll dp[100002];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt=1;
	for(int tc=1;tc<=tt;tc++){
		cin>>n>>k;
		vector<ll>coins(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>coins[i];
		}
		sort(coins.begin(),coins.end());
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		ll mx=0;
		for(int i=1;i<=n;i++){
			ll st=min(k,mx+coins[i])-1,en=max(0LL,st-coins[i]+1),sum=0;
			for(int j=st;j>=en;j--){
				sum+=dp[j];
			}
			bool flag=0;
			if(en==0) flag=1;
			for(ll wt=min(k,mx+coins[i]);wt>=0;wt--){
				if(wt==min(k,mx+coins[i])){
					
				}
				else{
					sum-=dp[wt];
				}
				if(en>0&&wt!=min(k,mx+coins[i])){
					sum+=dp[en];
				}
				if(en==0&&!flag){
					sum+=dp[en];
					flag=1;
				}
				dp[wt]+=max(0LL,sum);
				dp[wt]%=M;
				st--,en--;
			}
			mx=min(k,mx+coins[i]);
		}
		cout<<dp[k]<<endl;
	}
	return 0;
}

