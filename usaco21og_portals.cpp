#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=4e5+5;
int T=1,n,ans;
int fa[maxn],a[maxn][4];
int get_fa(int x)
{
	return fa[x]==x?x:fa[x]=get_fa(fa[x]);
}
void ins(int u,int v)
{
	int uu=get_fa(u),vv=get_fa(v);
	fa[uu]=vv;
}
struct node
{
	int id,w;
	bool operator < (const node &x) const
	{
		return w<x.w;
	}
};
node c[maxn];
void solve()
{
	scanf("%lld",&n);
	for(int i=1;i<=n*2;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld%lld",&c[i].w,&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		ins(a[i][0],a[i][1]);ins(a[i][2],a[i][3]);
		c[i].id=i;
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		int id=c[i].id;
		int uu=get_fa(a[id][0]);
		int vv=get_fa(a[id][2]);
		if(uu!=vv){
			fa[uu]=vv;
			ans+=c[i].w;
		}
	}
	printf("%lld\n", ans);
}
signed main()
{
	while(T--){
		solve();
	}
	return 0;
}

