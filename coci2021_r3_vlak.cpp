#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n;
int dp[200005][30],sum;
int f[200005];
string a;
bool cnt[2][200005];
void dfs2(string std,bool b){
	int size=std.size(),c=0;
	for(int i=0;i<size;i++){
		if(!dp[c][a[i]-'a'+1])dp[c][a[i]-'a'+1]=++sum;
		c=dp[c][a[i]-'a'+1];
		cnt[b][c]=1;
	}
	cnt[b][c]=1;
	return;
}
int dfs1(int x,bool y){
	if(~f[x])return f[x];
	if(y==0){
		for(int i=1;i<=26;i++){
			if(!dp[x][i]||!cnt[0][dp[x][i]])continue;
			if(!dfs1(dp[x][i],1))return f[x]=0;
		}
		return f[x]=1; 
	}
	else{
		for(int i=1;i<=26;i++){
			if(!dp[x][i]||!cnt[1][dp[x][i]])continue;
			if(dfs1(dp[x][i],0))return f[x]=1;
		}
		return f[x]=0; 
	}
}
signed main(){
	memset(f,-1,sizeof(f));
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a;
		dfs2(a,0); 
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a;
		dfs2(a,1);
	}
	dfs1(0,0);  
	if(!f[0])cout<<"Nina"; 
	else cout<<"Emilija";
	return 0;
}

