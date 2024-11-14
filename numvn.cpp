#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
template<typename T>void read(T &x){
	x=0;int f(1);char c(getchar());
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c-'0');
	x*=f;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x/10)write(x/10),x%=10;
	putchar(x+'0');
}
const int maxn=15,maxx=100005;
int tmp[maxn],vis[10];
long long dp[maxn][maxx][2],X;
long long dfs(int pos,int le,int _0,int up){
	if(pos==-1)return _0==0&&le==0;
	if(!up&&(~dp[pos][le][_0]))
		return dp[pos][le][_0];
	long long ans=0;
	int mx=up?tmp[pos]:9;
	for(int i=1;i<=mx;++i){
		if(vis[i])
			ans+=dfs(pos-1,(le*10+i)%X,_0&&i==0,up&&i==tmp[pos]);
	}
	if(_0)ans+=dfs(pos-1,0,1,up&&tmp[pos]==0);
	else if(vis[0])ans+=dfs(pos-1,le*10%X,false,up&&tmp[pos]==0);
	if(!up)dp[pos][le][_0]=ans;
	return ans;
}
long long solve(long long test){
	int cnt=0;
	while(test){
		tmp[cnt++]=test%10;test/=10;
	}
	return dfs(cnt-1,0,1,1);
}
int judge(long long test){
	while(test){
		if(!vis[test%10])return false;
		test/=10;
	}
	return true;
}
int main(){
	long long A,B;
	read(X),read(A),read(B);
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())vis[c-'0']=true;
	if(X<=maxx){
		memset(dp,-1,sizeof dp);
		write(solve(B)-solve(A-1));
		putchar('\n');
	}
	else{
		int l=(int)((A-1)/X+1),r=(int)(B/X),ans=0;
		for(int x=l;x<=r;++x)
			if(judge(1ll*X*x))++ans;
		write(ans),putchar('\n');
	}
	return 0;
}

