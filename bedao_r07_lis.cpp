#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,x,a[N];
set <ll> st;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for (ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (ll i=1;i<=n;i++){
		st.insert(a[i]);
		x+=st.size();
	}
	cout<<x;
}

