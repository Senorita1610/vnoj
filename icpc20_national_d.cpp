#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 300005
struct ed{
	int x,l,nx;
}e[M];
int nx[M],ecnt=1,fa[M],n;
ll mx1[M],mx2[M],mx3[M],f[M];
void clear(){
	ecnt=1;
	for(int i=1;i<=n;i++){
		f[i]=mx1[i]=mx2[i]=mx3[i]=0;
		fa[i]=nx[i]=0;
	}
}
void add(int x,int y,int l){
	e[ecnt]=(ed){y,l,nx[x]};
	nx[x]=ecnt++;
}
void dfs1(int x){
	for(int i=nx[x];i;i=e[i].nx){
		dfs1(e[i].x);
		f[x]=max(f[x],f[e[i].x]);
		ll tmp=mx1[e[i].x]+e[i].l;
		if(tmp>mx1[x]){
			mx3[x]=mx2[x];
			mx2[x]=mx1[x];
			mx1[x]=tmp;
		}
		else if(tmp>mx2[x]){
			mx3[x]=mx2[x];
			mx2[x]=tmp;
		}
		else if(tmp>mx3[x]){
			mx3[x]=tmp;
		}
	}
	f[x]=max(f[x],mx1[x]+mx2[x]);
}
ll res;
void dfs2(int x,long long l,long long mx){
	long long Mx1=0,Mx2=0;
	for(int i=nx[x];i;i=e[i].nx){
		if(f[e[i].x]>Mx1){
			Mx2=Mx1;
			Mx1=f[e[i].x];
		}
		else if(f[e[i].x]>Mx2){
			Mx2=f[e[i].x];
		}
	}
	for(int i=nx[x];i;i=e[i].nx){
		ll v=mx,nl=l+e[i].l;
		if(Mx1==f[e[i].x]){
			v=max(v,Mx2);
		}
		else{
			v=max(v,Mx1);
		}
		ll tmp=mx1[e[i].x]+e[i].l;
		if(mx1[x]!=tmp){
			nl=max(nl,mx1[x]+e[i].l);
			v=max(v,mx1[x]+l);
			if(mx2[x]!=tmp) v=max(v,mx1[x]+mx2[x]);
			else v=max(v,mx1[x]+mx3[x]);
		}
		else{
			nl=max(nl,mx2[x]+e[i].l);
			v=max(v,mx2[x]+l);
			v=max(v,mx2[x]+mx3[x]);
		}
		res=min(res,abs(f[e[i].x]-v));
		dfs2(e[i].x,nl,v);
	}
}
const ll inf=100000000000000000ll;
int main(){
	for(;;){
		scanf("%d",&n);
		if(n==0) return 0;
		for(int i=2;i<=n;i++){
			int l;
			scanf("%d%d",&fa[i],&l);
			add(fa[i],i,l);
		}
		res=inf;
		dfs1(1);
		dfs2(1,0,0);
		printf("%lld\n",res);
		clear();
	}
	return 0;
}

