#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,c,inf=1e9;
int a[N+5];
bool flag=true;
pair<int,int> st[N*4+5];
void build(int id,int l,int r) {
	if (l==r) {
		st[id].first=st[id].second=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].first=min(st[id*2].first,st[id*2+1].first);
	st[id].second=max(st[id*2].second,st[id*2+1].second);
}
int getmax(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return -inf;
	if (u<=l&&r<=v) return st[id].second;
	int mid=(l+r)/2;
	return max(getmax(id*2,l,mid,u,v),getmax(id*2+1,mid+1,r,u,v));
}
int getmin(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return inf;
	if (u<=l&&r<=v) return st[id].first;
	int mid=(l+r)/2;
	return min(getmin(id*2,l,mid,u,v),getmin(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>c;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for (int i=1;i+m-1<=n;i++) {
		int mx=getmax(1,1,n,i,i+m-1);
		int mn=getmin(1,1,n,i,i+m-1);
		if (mx-mn<=c) {
			cout<<i<<'\n';
			flag=false;
		}
	}
	if (flag) cout<<"NONE";
}

