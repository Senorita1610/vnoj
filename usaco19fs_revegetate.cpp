#include <bits/stdc++.h>
#define reg register
using namespace std;
const int MaxN=100050;
struct Edge
{
	int nxt,to,w;
}E[MaxN<<2];
struct Quetion
{
	int opt,u,v;
}Q[MaxN<<1];
template <class t> inline void read(t &s)
{
	s=0;
	reg int f=1;
	reg char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	s*=f;
	return;
}
int hd[MaxN],en,n,m;
int col[MaxN];
inline void adde(int u,int v,int w)
{
	++en;
	E[en]=(Edge){hd[u],v,w};
	hd[u]=en;
	return;
}
inline void dfs(int u,int fa)
{
	for(int i=hd[u];~i;i=E[i].nxt)
	{
		reg int v=E[i].to;
		if(v==fa||col[v]!=-1)
			continue;
		if(!E[i].w)
			col[v]=col[u];
		else
			col[v]=1-col[u];
		dfs(v,u);
	}
	return;
}
signed main(void)
{
	memset(hd,-1,sizeof hd);
	memset(col,-1,sizeof col);
	cin>>n>>m;
	reg int u,v;
	char opt[3];
	for(int i=1;i<=m;++i)
	{
		scanf("%s",opt);
		read(u);read(v);
		Q[i]=(Quetion){
			0,u,v
		};
		if(opt[0]=='S')
			adde(u,v,0),adde(v,u,0);
		else
			adde(u,v,1),adde(v,u,1),Q[i].opt=1;
	}
	reg int ans=0;
	for(int i=1;i<=n;++i)
		if(col[i]==-1)
		{
			++ans;
			col[i]=0;
			dfs(i,0);
		}
	for(int i=1;i<=m;++i)
		if(!Q[i].opt)
		{
			if(col[Q[i].u]!=col[Q[i].v])
			{
				puts("0");
				return 0;
			}
		}
		else
		{
			if(col[Q[i].u]==col[Q[i].v])
			{
				puts("0");
				return 0;
			}
		}
	printf("1");
	for(int i=1;i<=ans;++i)
		putchar('0');
	puts("");
	return 0;
}

