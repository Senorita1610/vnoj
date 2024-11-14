#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int a,b,c1,c2,k;
	cin>>a>>b>>c1>>c2>>k;
	if(c1<c2) swap(c1,c2);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		if(a*x+b*y-c1>=0) cnt1++;
		if(a*x+b*y-c2<=0) cnt2++;
	}
	if(cnt1==k||cnt2==k) cout<<"NO\n";
	else cout<<"YES\n";
}
int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int test;
	cin>>test;
	while(test--) solve();
}

