#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+100;
struct node{
	int st,ed,w;
	bool operator < (const node &x)const{
		return ed<x.ed;
	}
}a[N];
long long t[N<<2],lazy[N<<2];
int n,m;
void pushdown(int p){
	if(lazy[p]){
		t[2*p]+=lazy[p];
		t[2*p+1]+=lazy[p];
		lazy[2*p]+=lazy[p];
		lazy[2*p+1]+=lazy[p];
		lazy[p]=0;
	}
}
void update(int p,int l,int r,int x,int y,long long v){
	if(x<=l&&r<=y){
		t[p]+=v;
		lazy[p]+=v;
		return;
	}
	pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid) update(2*p,l,mid,x,y,v);
	if(mid+1<=y) update(2*p+1,mid+1,r,x,y,v);
	t[p]=max(t[2*p],t[2*p+1]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].st,&a[i].ed,&a[i].w);
	sort(a+1,a+m+1);
	int j=1;
	for(int i=1;i<=n;i++){
		update(1,1,n,i,i,max(0ll,t[1]));
		while(a[j].ed==i&&j<=m){
			update(1,1,n,a[j].st,a[j].ed,a[j].w);
			j++;
		}
	}
	printf("%lld\n",max(0ll,t[1]));
	return 0;
}

