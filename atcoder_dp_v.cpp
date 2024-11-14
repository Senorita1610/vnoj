#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
inline int read(){
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return s;
}
int n,ect=2,hd[N],fa[N];
ll md,f[N],g[N];
struct E{
	int v,nt;
}e[2*N];
void add(int u,int v){
	e[ect].v=v;
	e[ect].nt=hd[u];
	hd[u]=ect++;
}
void dfs1(int p){
	f[p]=1;
	for(int i=hd[p];i;i=e[i].nt){
		if(e[i].v==fa[p]) continue;
		fa[e[i].v]=p;
		dfs1(e[i].v);
		f[p]=f[p]*(f[e[i].v]+1)%md;
	}
}
void dfs2(int p){
	ll nj=1;
	vector<int>stc;
	for(int i=hd[p];i;i=e[i].nt){
		if(e[i].v==fa[p]) continue;
		g[e[i].v]=g[p]+1;
		g[e[i].v]=g[e[i].v]*nj%md;
		nj=nj*(f[e[i].v]+1)%md;
		stc.push_back(e[i].v);
	}
	nj=1;
	int top=stc.size()-1;
	while(top>=0){
		g[stc[top]]=g[stc[top]]*nj%md;
		nj=nj*(f[stc[top]]+1)%md;
		dfs2(stc[top--]);
	}
}
int main(){
	n=read();md=read();
	int u,v;
	for(int i=1;i<n;i++){
		u=read();v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;i++){
		printf("%lld\n",f[i]*(g[i]+1)%md);
	}
	return 0;
}

