#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long h[N+5],a[N+5],res;
vector<long long>cprs;
pair<int,int>st[N*4+5];
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id].first=min(st[id].first,val);
		st[id].second=max(st[id].second,val);
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id].first=min(st[id*2].first,st[id*2+1].first);
	st[id].second=max(st[id*2].second,st[id*2+1].second);
}
pair<int,int>get(int id,int l,int r,int u,int v) {
	if (u>r||v<l) return {n+1,0};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	pair<int,int>g1=get(id*2,l,mid,u,v),g2=get(id*2+1,mid+1,r,u,v);
	return {min(g1.first,g2.first),max(g1.second,g2.second)};
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>h[i];
    	cprs.push_back(h[i]);	
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=4*n;i++) st[i]={n+1,0};
    for (int i=1;i<=n;i++) {
    	a[i]=lower_bound(cprs.begin(),cprs.end(),h[i])-cprs.begin()+1;
    	update(1,1,n,a[i],i);
    }
    for (int i=1;i<=n;i++) {
    	pair<int,int>p=get(1,1,n,a[i],n);
    	int l=p.first,r=p.second;
    	if (l<i) res=max(res,h[i]*(i-l-1));
    	if (r>i) res=max(res,h[i]*(r-i-1));
    }
    cout<<res;
}

