#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q;
int a[N+5],mx[N+5],last[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=q;i++) {
		int type,k,x;
		cin>>type;
		if (type==1) {
			cin>>k>>x;
			a[k]=x;
			last[k]=i;
		} else {
			cin>>x;
			mx[i]=x;
		}
	}
	for (int i=q;i>=0;i--) mx[i]=max(mx[i],mx[i+1]);
	for (int i=1;i<=n;i++) cout<<max(a[i],mx[last[i]])<<' ';
}

