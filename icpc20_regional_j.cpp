#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
ll cnt(ll n,ll thresh){
	ll ret=(1<=thresh&&1<=n)+(2<=thresh&&2<=n);
	ll cur=2;
	while(cur+1<=n){
		ll nxt=3*cur-1;
		if(nxt<=n){
			ret+=min(thresh,cur-1);
			ret+=min(nxt,thresh)-min(2*cur-1,thresh);
		}else{
			ll x=(n-cur)/2;
			ret+=min(thresh,cur-1)-min(thresh,cur-1-x);
			ll y=(n-cur+1)/2;
			ret+=min(thresh,2*cur-1+y)-min(2*cur-1,thresh);
		}
		cur=nxt;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin>>tc;
	for(int cs=1;cs<=tc;cs++){
		ll n,k;
		cin>>n>>k;
		ll lo=1,hi=4e18;
		while(lo<=hi){
			ll mid=(hi+lo)/2;
			if(cnt(n,mid)<k){
				lo=mid+1;
			}else{
				hi=mid-1;
			}
		}
		cout<<lo<<endl;
	}
	return 0;
}

