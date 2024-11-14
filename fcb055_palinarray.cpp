#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int last[N+5],a[N+5];
bool flag;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		flag=false;
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			last[a[i]]=i;
		}
		for (int i=1;i<=n;i++) {
			if (last[a[i]]>i+1) {
				flag=true;
				break;
			}
		}
		if (flag) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
		for (int i=1;i<=n;i++) last[a[i]]=0;
	}
}

