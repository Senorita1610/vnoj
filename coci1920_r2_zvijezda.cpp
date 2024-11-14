#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define crep(i,x,n) for(int i=x;i<n;i++)
#define drep(i,n) for(int i=n-1;i>=0;i--)
#define vec(...) vector<__VA_ARGS__>
#define _32bB6rn ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
using pii=pair<int,int>;
using pll=pair<long long,long long>;
using vi=vector<int>;
 
 
ld ccw(pll a,pll b,pll c){
	return (ld)a.fi * (b.se - c.se) +
			(ld)b.fi * (c.se - a.se) +
			(ld)c.fi * (a.se - b.se);
}
 
bool get(pll a,pll b,pll c){
	// ccw -> false
	return ccw(a,b,c)<0;
}
 
int main(){
_32bB6rn;
	ll _t;
	cin>>_t;
	int n;
	cin>>n;
	vec(pll) a(n);
	rep(i,n){
		cin>>a[i].fi>>a[i].se;
	}
	auto affine=[&](int i,pll p)->int{
		int j=(i+n/2+1+n)%n;
		bool pok=!get(a[i],a[(i+1)%n],p) and get(a[j],a[(j-1+n)%n],p);
		pok=pok or (get(a[(i+1)%n],a[i],p) and !get(a[(j-1+n)%n],a[j],p));
		return pok?2:!get(a[i],a[(i+1)%n],p)?1:3;
	};
	auto bs=[&](pll p)->bool{
		int l=0,r=n-1,c=-1;
		while(l<=r){
			int m=(l+r)>>1;
			int val=affine(m,p);
			if(val==2) return true;
			if(val==1){
				l=m+1;
			}else{
				r=m-1;
			}
		}
		return false;
	};
 
	int q;
	cin>>q;
	ll ans=0;
	rep(_,q){
		ll x,y;
		cin>>x>>y;
		x=x^(_t*ans*ans*ans);
		y=y^(_t*ans*ans*ans);
		bool pok=bs({x,y});
		cout<<(pok?"DA\n":"NE\n");
		ans+=pok;
	}
	return 0;
}

