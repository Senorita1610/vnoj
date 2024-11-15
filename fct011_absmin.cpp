#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,ans=1e+18,a[N];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (ll i=2;i<=n;i++)
        ans=min(ans,abs(a[i]-a[i-1]));
    cout<<ans;
}

