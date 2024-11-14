#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int t,n,a[N+5],c[N+5];
long long dp[N+5];
vector<int>cprs;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cprs.clear();
    	cin>>n;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		cprs.push_back(a[i]);
    	}
    	sort(cprs.begin(),cprs.end());
    	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    	for (int i=1;i<=n;i++) {
    		a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
    		dp[i]=dp[i-1]+c[a[i]];
    		c[a[i]]+=i;
    	}
    	long long res=0;
    	for (int i=1;i<=n;i++) {
    		c[a[i]]=0;
    		res+=dp[i];
    	}
    	cout<<res<<'\n';
    }	
}

