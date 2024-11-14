#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#include<bits/stdc++.h>
using namespace std;
#define y1 y11
#define fi first
#define se second
#define pi acos(-1.0)
#define LL long long
#define pb push_back
#define ls rt<<1,l,m
#define rs rt<<1|1,m+1,r
#define ULL unsigned LL
#define pll pair<LL,LL>
#define pli pair<LL,int>
#define pii pair<int,int>
#define piii pair<pii, int>
#define pdd pair<double,double>
#define mem(a,b) memset(a,b,sizeof(a))
#define debug(x) cerr<<#x<<" = "<<x<<"\n";
const int N=20;
char s[N][N];
pii a[N];
int n,m,cnt,num[N];
LL p[N];
map<LL,int>dp[2];
int main(){
	p[0]=1;
	for(int i=1;i<N;i++) p[i]=p[i-1]*10;
	while(~scanf("%d %d",&n,&m)){
		if(!n&&!m) break;
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(isdigit(s[i][j])){
					a[cnt].fi=i;
					a[cnt].se=j;
					num[cnt]=s[i][j]-'0';
					++cnt;
				}
			}
		}
		dp[0].clear();dp[1].clear();
		int now=0;
		dp[now][0]=0;
		int k;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				now^=1;
				dp[now].clear();
				for(auto t : dp[now^1]){
					LL x=t.fi;
					for(k=0;k<cnt;k++){
						if((x/p[k])%10!=num[k] && (i*m+j)-(a[k].fi*m+a[k].se)>=m+2) break;
					}
					if(k<cnt) continue;
					if(dp[now].find(x)==dp[now].end()) dp[now][x]=t.se;
					else dp[now][x]=min(dp[now][x],t.se);
					if(s[i][j]=='.') continue;
					for(k=0;k<cnt;k++){
						if(i-1<=a[k].fi&&a[k].fi<=i+1&&j-1<=a[k].se&&a[k].se<=j+1){
							if((x/p[k])%10==num[k]) break;
							x+=p[k];
						}
					}
					if(k<cnt) continue;
					if(dp[now].find(x)==dp[now].end()) dp[now][x]=t.se+1;
					else dp[now][x]=min(dp[now][x],t.se+1);
				}
			}
		}
		LL x=0;
		for(int i=0;i<cnt;i++) x+=num[i]*p[i];
		printf("%d\n",dp[now][x]);
	}
	return 0;
}

