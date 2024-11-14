#include<bits/stdc++.h>
#define ll int
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
using namespace std;
set<pll>S;
vector<ll>B[1000005];
ll c[1000005],cnt[1000005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=1;i<=n*n;i++){
		cin>>c[i];
		cnt[c[i]]++;
	}
	for(ll i=1;i<=n+1;i++){
		if(cnt[i]!=0){
			S.insert({cnt[i],i});
		}
	}
	for(ll i=1;i<=n;i++){
		ll v,c;
		tie(v,c)=*S.begin();
		S.erase(S.begin());
		if(v>=n){
			v-=n;
			for(ll j=1;j<=n;j++) B[c].pb(i);
			if(v) S.insert({v,c});
		}
		else{
			auto ptr=S.lower_bound(mp(n-v,0));
			S.erase(ptr);
			ll v1=(*ptr).fi,c1=(*ptr).se;
			for(ll j=1;j<=v;j++)B[c].pb(i);
			for(ll j=1;j<=n-v;j++) B[c1].pb(i);
			v1-=n-v;
			if(v1) S.insert({v1,c1});
		}
	}
	cout<<"YES\n";
	for(ll i=1;i<=n*n;i++){
		cout<<B[c[i]].back()<<" ";
		B[c[i]].pop_back();
	}
}

