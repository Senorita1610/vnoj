#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define N 100005
using namespace std;
int n,m,k,a[30][30];
char s[N];
int sum[30][N];
void init(int col){
	rep(i,1,n)sum[col][i]=sum[col][i-1]+a[s[i]-'a'+1][col];
}
int mx[30];
int f[N];
void floyd(){
	rep(k,1,m)
	  rep(i,1,m)
	    rep(j,1,m)
		  if(i^j)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}
void work(){
	memset(f,0x7f,sizeof(f));
	f[0]=0;
	rep(i,k,n){
		rep(col,1,m)mx[col]=max(mx[col],sum[col][i-k]-f[i-k]);
		rep(col,1,m)f[i]=min(f[i],sum[col][i]-mx[col]);
	}
	printf("%d\n",f[n]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s+1);
	rep(i,1,m)rep(j,1,m)scanf("%d",&a[i][j]);
	floyd();
	rep(i,1,m)init(i);
	work();
	return 0;
}

