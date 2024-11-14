#include<bits/stdc++.h>
using namespace std;
map<int,int>s,kc;
int t,hl,ml,hr,mr,alpha;
int main(){
	s[180]=360;s[90]=180;s[0]=0;
	kc[0]=720;kc[90]=360;kc[180]=720;
	cin>>t;
	while(t--){
		char c;
		cin>>hl>>c>>ml>>hr>>c>>mr>>alpha;
		int l=11*(hl*60+ml);
		int r=11*(hr*60+mr);
		int ans=0;
		int d=s[alpha];
		while(d<=r){
			if(d>=l) ++ans;
			d+=kc[alpha];
		}
		cout<<ans<<endl;
	}
	return 0;
}

