#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int NS=1100;
const int INF=1<<30;
struct node{
	int r,c;
	bool operator < (const node cmp) const{
		return c<cmp.c;
	}
}a[NS];
int n,m,k,b;
int mix,tmp,pre,now,res;
int h[NS],s[NS],dp[2][NS][4];
void init(int f){
	for(int i=0;i<=k;i++)
	for(int j=0;j<4;j++)
	dp[f][i][j]=INF;
}
int Min(int xa,int xb){
	return xa<xb?xa:xb;
}
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		scanf("%d%d%d",&n,&k,&b);
		for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].r,&a[i].c);
		sort(a,a+n),init(0);
		pre=1,now=0,m=-1,res=INF;
		for(int i=0;i<n;i++)
		if(i==0||(a[i].c!=a[i-1].c)) h[++m]=a[i].c,s[m]=a[i].r;
		else s[m]+=a[i].r;
		dp[now][2][0]=dp[now][1][3]=2;
		if(s[0]!=3) dp[now][1][s[0]]=1;
		for(int i=1;i<=m;i++){
			pre^=1,now^=1,init(now);
			for(int j=0;j<=k;j++){
				tmp=h[i]-h[i-1];
				mix=Min(Min(dp[pre][j][0],dp[pre][j][1]),Min(dp[pre][j][2],dp[pre][j][3]));
				dp[now][j+2][0]=Min(dp[now][j+2][0],mix+2);
				dp[now][j+1][3]=Min(dp[now][j+1][3],mix+2);
				dp[now][j][0]=Min(dp[now][j][0],dp[pre][j][0]+2*tmp);
				dp[now][j][3]=Min(dp[now][j][3],dp[pre][j][3]+2*tmp);
				if(s[i]==1||s[i]==2)
				dp[now][j+1][s[i]]=Min(dp[now][j+1][s[i]],mix+1),
				dp[now][j][s[i]]=Min(dp[now][j][s[i]],Min(dp[pre][j][s[i]]+tmp,dp[pre][j][0]+tmp));
				dp[now][j+1][0]=Min(dp[now][j+1][0],Min(dp[pre][j][1]+1+tmp,dp[pre][j][2]+1+tmp));
			}
		}
		for(int i=0;i<=k;i++)
		for(int j=0;j<4;j++)
		res=Min(res,dp[now][i][j]);
		printf("%d\n",res);
	}
	return 0;
}

