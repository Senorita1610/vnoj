#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    while (q--) {
    	int l,r,val;
    	cin>>l>>r>>val;
    	int id=lower_bound(a+l,a+1+r,val)-a;
    	if (id<l||id>r||a[id]<val) cout<<-1<<'\n';
    	else cout<<a[id]<<'\n';
    }
}

