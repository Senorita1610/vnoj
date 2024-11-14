#include<bits/stdc++.h>
#define rgt register
#define rint rgt int
#define LL long long
#define rll rgt LL
#define inf 0x7f7f7f7f
#define N 2003
using namespace std;
template<class K>inline bool cmax(K&a,const K&b){return(a<b)?a=b,1:0;}
template<class K>inline bool cmin(K&a,const K&b){return(a>b)?a=b,1:0;}
inline int read() {
	rgt int s=0;
	rgt char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) s=(s<<1)+(s<<3)+c-'0',c=getchar();
	return s;
}
int k,n,m,f[N][N],g[N][N],ans=inf;
inline void solve1(rint val) {
	rint l=1,r=n,i=1,j=m;
	while(i<=j) {
		if(g[r][i]-g[l-1][i]<=k) ++i;
		else if(g[r][j]-g[l-1][j]<=k) --j;
		else if(l<=val&&f[l][j]-f[l][i-1]<=k)
			while(l<=val&&f[l][j]-f[l][i-1]<=k) ++l;
		else if(f[r][j]-f[r][i-1]<=k) --r;
		else return;
	}cmin(ans,n+m-(r-l+1));
}
inline void solve2(rint val) {
	rint l=1,r=m,i=1,j=n;
	while(i<=j) {
		if(f[i][r]-f[i][l-1]<=k) ++i;
		else if(f[j][r]-f[j][l-1]<=k) --j;
		else if(l<=val&&g[j][l]-g[i-1][l]<=k)
			while(l<=val&&g[j][l]-g[i-1][l]<=k) ++l;
		else if(g[j][r]-g[i-1][r]<=k) --r;
		else return;
	}cmin(ans,n+m-(r-l+1));
}
int main() {
	rint i,j,c;k=read(),m=read(),n=read();
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			c=read(),
			f[i][j]=f[i][j-1]+c,
			g[i][j]=g[i-1][j]+c;
	for(i=0;i<=n;i++) solve1(i);
	for(j=0;j<=m;j++) solve2(j);
	printf("%d",ans);
	return 0;
}

