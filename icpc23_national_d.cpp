#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main(){
	int t;
	cin>>t;
	while(t--){
		mp.clear();
		int n;
		cin>>n;
		int lst=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(mp[x]>0) lst=max(lst,mp[x]);
			ans+=i-lst;
			mp[x]=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

