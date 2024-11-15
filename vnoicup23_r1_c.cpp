#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll t,n,a[N],b[N],ans;
void Solve(){
    cin>>n;
    ans=0;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1,greater<ll>());
    for (ll i=1;i<=n;i++) ans+=max(a[i],b[i]);
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

