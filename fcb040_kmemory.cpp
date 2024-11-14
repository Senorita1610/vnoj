#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
long long res,k,mn,mx,a[N+5];
multiset<long long>s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1;
    s.insert(a[1]);
    mn=mx=a[1];
    while (l<=n) {
    	while (r+1<=n&&abs(a[r+1]-mn)<=k&&abs(a[r+1]-mx)<=k) {
    		r++;
    		s.insert(a[r]);
    		mn=min(mn,a[r]);
    		mx=max(mx,a[r]);
    	}
    	res+=r-l+1;
    	s.erase(s.lower_bound(a[l]));
    	l++;
    	if (l>r) {
    		r=l;
    		s.insert(a[l]);
    		mn=mx=a[l];
    	}
    	mn=*s.begin();
    	mx=*s.rbegin(); 
    }
    cout<<res;
}

