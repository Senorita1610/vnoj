#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
const int N=2e5+10;
struct Node{
	LL l,r;
	int len;
	int cnt;
}tr[N<<3];
struct Line{
	int x,y1,y2;
	int op;
	bool operator<(const Line &W) const {
		return x<W.x;
	}
}X[N<<1];
int num[N<<1];
void pushup(int u){
	if(tr[u].cnt) tr[u].len=tr[u].r-tr[u].l;
	else tr[u].len=tr[u<<1].len+tr[u<<1|1].len;
}
void build(int u,int l,int r){
	tr[u]={num[l],num[r]};
	if(l+1==r) return;
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid,r);
}
void modify(int u,int l,int r,int op){
	if(tr[u].r<=l||tr[u].l>=r) return;
	if(tr[u].l>=l&&tr[u].r<=r) tr[u].cnt+=op;
	else{
		modify(u<<1,l,r,op);
		modify(u<<1|1,l,r,op);
	}
	pushup(u);
}
signed main(){
	int k,n;
	cin>>k>>n;
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		char op[2];
		int d;
		scanf("%s%lld",op,&d);
		int x1=x,y1=y,x2=x+k,y2=y+k;
		if(*op=='N') y2+=d,y+=d;
		else if(*op=='S') y1-=d,y-=d;
		else if(*op=='W') x1-=d,x-=d;
		else if(*op=='E') x2+=d,x+=d;
		X[i]={x1,y1,y2,1};
		X[i+n]={x2,y1,y2,-1};
		num[i]=y1,num[i+n]=y2;
	}
	n*=2;
	sort(X+1,X+n+1);
	sort(num+1,num+n+1);
	build(1,1,n);
	LL res=0;
	for(int i=1;i<n;i++){
		modify(1,X[i].y1,X[i].y2,X[i].op);
		res+=(X[i+1].x-X[i].x)*(LL)tr[1].len;
	}
	cout<<res<<endl;
	return 0;
}

