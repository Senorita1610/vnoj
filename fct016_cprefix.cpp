#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
string s;
long long mod=1e9+7,base=31;
long long hs[N+5],power[N+5],t[N+5];
void create_hash() {
	n=s.size();
	s=' '+s;
	power[0]=1;
	for (int i=1;i<=n;i++) {
		power[i]=power[i-1]*base%mod;
		hs[i]=(hs[i-1]*base%mod+s[i]-'a'+1)%mod;
	}
}
long long get(int l,int r) {
	return ((hs[r]-hs[l-1]*power[r-l+1])%mod+mod)%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    create_hash();
    for (int i=1;i<=n;i++) {
    	int lo=1,hi=n-i+1,ans=0;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (get(1,mid)==get(i,i+mid-1)) {
    			ans=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    	t[1]++;
    	t[ans+1]--;
    }
    for (int i=1;i<=n;i++) {
    	t[i]+=t[i-1];
    	cout<<t[i]<<' ';
    }
}

