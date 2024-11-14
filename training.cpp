#include<bits/stdc++.h>
using namespace std;
const int maxn=5100;
int n,m,ans=0;
int tot=0,pre[maxn],now[maxn],son[maxn];
int u[maxn],v[maxn],w[maxn],mx[maxn],h[maxn];
int fa[maxn],dep[maxn],cnt[maxn],G[maxn][12],fid[maxn];
int f[maxn],g[maxn];
int tmp[1<<10];
vector<int>S[maxn];
void put(int x,int y){
	pre[++tot]=now[x];
	now[x]=tot;
	son[tot]=y;
}
int LCA(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	while(dep[x]>dep[y]) x=fa[x];
	while(x!=y) x=fa[x],y=fa[y];
	return x;
}
void dfs1(int x,int ff){
	fa[x]=ff,dep[x]=dep[ff]+1;
	for(int p=now[x];p;p=pre[p]){
		int t=son[p];
		if(t==ff) continue;
		dfs1(t,x);
	}
}
void dfs2(int x){
	for(int p=now[x];p;p=pre[p]){
		int t=son[p];
		if(t==fa[x]) continue;
		G[x][++cnt[x]]=t,fid[t]=cnt[x];
		dfs2(t);
	}
	memset(tmp,0,sizeof(tmp));
	int ss=(1<<cnt[x])-1;
	for(int i:S[x]){
		int p=u[i],q=v[i],s=0;
		if(p!=x){
			h[i]+=f[p];
			while(fa[p]!=x){
				h[i]+=g[p],p=fa[p];
			}
			s|=(1<<(fid[p]-1));
		}
		if(q!=x){
			h[i]+=f[q];
			while(fa[q]!=x) h[i]+=g[q],q=fa[q];
			s|=(1<<(fid[q]-1));
		}
		for(int j=0;j<=ss;j++){
			if(!(j&s)){
				tmp[j|s]=max(tmp[j|s],tmp[j]+w[i]+h[i]);
			}
		}
	}
	for(int j=0;j<=ss;j++){
		for(int k=1;k<=cnt[x];k++){
			if(!(j&(1<<(k-1)))) tmp[j]+=f[G[x][k]];
		}
		for(int k=1;k<=cnt[x];k++){
			if(!(j&(1<<(k-1)))) g[G[x][k]]=max(g[G[x][k]],tmp[j]-f[G[x][k]]);
		}
		f[x]=max(f[x],tmp[j]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		if(!w[i]) put(u[i],v[i]),put(v[i],u[i]);
	}
	dfs1(1,0);
	for(int i=1;i<=m;i++){
		if(w[i]){
			mx[i]=LCA(u[i],v[i]),ans+=w[i];
			if(!((dep[u[i]]+dep[v[i]])&1)) S[mx[i]].push_back(i);
		}
	}
	dfs2(1);
	printf("%d\n",ans-f[1]);
	return 0;
}

