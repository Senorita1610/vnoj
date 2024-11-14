#include<bits/stdc++.h>
using namespace std;
int fa[100010],ans[100010],M,N;
char col[100010];
int find(int x)
{
	if(x==fa[x])	return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
int main()
{
	int cnt=0;
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		fa[i]=i;
		cin>>col[i];
	}	
	for(int i=1;i<=N-1;i++)
	{
		int u,v;cin>>u>>v;
		if(col[u]==col[v])	merge(u,v);
	}
	for(int i=1;i<=M;i++)
	{
		int a,b; cin>>a>>b;
		char c;	cin>>c;
		if(find(a)==find(b)&&col[a]!=c) ans[++cnt]=0;
		else	ans[++cnt]=1;
	}
	for(int i=1;i<=cnt;i++)	cout<<ans[i];
	return 0;
}

