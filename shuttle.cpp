#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+10;
int n,k,ans,c;
struct Line{
	int m,l,r;
	bool operator<(const Line& l2)const{
		return r < l2.r;
	}
}line[MAXN];
int zt[MAXN];
int tree[MAXN<<2],tag[MAXN<<2];
inline int lc(int x){return x<<1;}
inline int rc(int x){return lc(x)|1;}
void push_up(int);
void push_down(int);
int query(int,int,int,int,int);
void update(int,int,int,int,int,int);
int main(){
	scanf("%d%d%d",&k,&n,&c);
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&line[i].l,&line[i].r,&line[i].m);
	}
	sort(line+1,line+1+k);
	for(int i=1;i<=k;i++){
		int l = line[i].l,r = line[i].r,m = line[i].m;
		//max [l,r)
		int maxn = query(1,1,n,l,r-1);
		int chose =((c-maxn) < m)?(c-maxn):m;
		ans += chose;
		//[l,r) += chose
		update(1,1,n,l,r-1,chose);
	}
	cout<<ans;
	return 0;
}
void push_up(int x){
	tree[x] = max(tree[lc(x)],tree[rc(x)]);
}
void push_down(int x){
	tree[lc(x)] += tag[x];
	tree[rc(x)] += tag[x];
	tag[lc(x)] += tag[x];
	tag[rc(x)] += tag[x]; 
	tag[x] = 0; 
}
int query(int x,int l,int r,int ql,int qr){
	if(ql <= l && qr >= r){
		return tree[x];
	}
	int mid = (l+r)>>1;
	int ans = 0;
	push_down(x);
	if(ql <= mid){
		ans = max(ans,query(lc(x),l,mid,ql,qr));
	}
	if(qr > mid){
		ans = max(ans,query(rc(x),mid+1,r,ql,qr));
	}
	push_up(x);
	return ans;
}
void update(int x,int l,int r,int ql,int qr,int value){
	if(ql <= l && qr >= r){
		tree[x] += value;
		tag[x] += value;
		return;
	}
	int mid = (l+r)>>1;
	push_down(x);
	if(ql <= mid){
		update(lc(x),l,mid,ql,qr,value);
	}
	if(qr > mid){
		update(rc(x),mid+1,r,ql,qr,value);
	}
	push_up(x);
}

