#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q,cur,l,r;
long long x;
long long a[N+5];
struct Node{
	long long val,lazy;
} st[N*4+5];
void down(int id,int l,int r) {
	long long temp=st[id].lazy;
	st[id].lazy=0;
	st[id*2].lazy+=temp;
	st[id*2+1].lazy+=temp;
	int mid=(l+r)/2;
	st[id*2].val+=(mid-l+1)*temp;
	st[id*2+1].val+=(r-mid)*temp;
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id].val=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].val=st[id*2].val+st[id*2+1].val;
}
void update(int id,int l,int r,int u,int v,long long val) {
	if (l>v||u>r) return;
	if (u<=l&&r<=v) {
		st[id].val+=(r-l+1)*val;
		st[id].lazy+=val;
		return;
	}
	down(id,l,r);
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id].val=st[id*2].val+st[id*2+1].val;
}
long long get(int id,int l,int r,int pos) {
	if (l>pos||r<pos) return 0;
	if (l==r) return st[id].val;
	down(id,l,r);
	int mid=(l+r)/2;
	return get(id*2,l,mid,pos)+get(id*2+1,mid+1,r,pos);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for (int i=1;i<n;i++) cur+=(a[i]>a[i+1]);
    while (q--) {
    	cin>>l>>r>>x;
    	if (l>1) {
    		long long t1=get(1,1,n,l),t2=get(1,1,n,l-1);
    		if (t1>=t2&&t1+x<t2) cur++;
    		if (t1<t2&&t1+x>=t2) cur--;
    	}
    	if (r<n) {
    		long long t1=get(1,1,n,r),t2=get(1,1,n,r+1);
    		if (t1>t2&&t1+x<=t2) cur--;
    		if (t1<=t2&&t1+x>t2) cur++;
    	}
    	update(1,1,n,l,r,x);
    	cout<<cur<<'\n';
    }
}

