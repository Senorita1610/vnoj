#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7,N=1e6+5;
string str;
int n,k,now;
int dp[N]={},ans[N]={};
signed main(){
	cin>>str;
	n=str.size();
	for(int i=1;i<=n;i++) dp[i]=(dp[i-1]*10+(str[i-1]-'0')*i)%MOD;
	for(int i=1;i<=n;i++) ans[i]=(ans[i-1]*100+(str[i-1]-'0')*(str[i-1]-'0')*i+(str[i-1]-'0')*20*dp[i-1])%MOD;
	for(int i=1;i<=n;i++) now=(now+ans[i])%MOD;
	cout<<now%MOD<<endl;
	return 0;
}

