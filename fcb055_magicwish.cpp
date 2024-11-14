#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,p,q;
long long a[N+5];
vector<long long>temp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		temp.clear();
		cin>>n>>p>>q;
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		long long res=a[n]-a[1];
		for (int i=2;i<n;i++) temp.push_back(abs(a[i]));
		sort(temp.begin(),temp.end(),greater<long long>());
		int t=min((int)temp.size(),p+q);
		for (int i=0;i<t;i++) res+=temp[i];
		cout<<res<<'\n';
	}
}

