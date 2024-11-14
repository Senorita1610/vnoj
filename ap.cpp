#include<bits/stdc++.h>
#define f(i,a,b) for (int i=(a);i<=(b);i++)
#define df(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define int long long
#define fi first
#define se second
using namespace std;
const int N=2e2;
int cs,fg,m,n,x,y,f[N][N],fa[N],lk[N],nw[N],fb[N];
vector<int>a[N],b[N];
bool p(int v,int e)
{
	for(int j=nw[v],u;j<a[e].size();j++)if((u=a[e][j])!=fa[e]&&f[u][v])if(!lk[u]||p(lk[u],e)){lk[u]=v,nw[v]=j+1;return 1;}
	return 0;
}
void D1(int e)
{
	for(auto u:b[e])if(u!=fb[e])fb[u]=e,D1(u);
}
void D(int e)
{
	for(auto u:a[e])if(u!=fa[e])fa[u]=e,D(u);
	f(i,1,m)
	if(i!=1&&b[i].size()==1)f[e][i]=1;
	else if(a[e].size()-(!!fa[e])>=b[i].size()-(i!=1))
	{
		f[e][i]=1;
		for(auto u:a[e])lk[u]=0;
		for(auto u:b[i])nw[u]=0;
		for(auto u:b[i])if(u!=fb[i]&&!p(u,e)){f[e][i]=0;break;}
	}
	if(f[e][1])fg=1;
}
signed main() 
{
	scanf("%lld",&cs);
	for(int tt=1;tt<=cs;tt++)
	{
		scanf("%lld",&n);
		fg=0;
		f(i,1,n)a[i].clear(),b[i].clear();
		f(i,1,n-1)scanf("%lld%lld",&x,&y),a[x].pb(y),a[y].pb(x);
		scanf("%lld",&m);
		f(i,1,m-1)scanf("%lld%lld",&x,&y),b[x].pb(y),b[y].pb(x);
		D1(1);
		f(i,1,n)
		{
			memset(f,0,sizeof(f)),fa[i]=0,D(i);
			if(fg)break;
		}
		if(fg){
		    cout<<"Case #"<<tt<<": "<<"YES\n";
		}
		else cout<<"Case #"<<tt<<": "<<"NO\n";
	}
	return 0;
}

