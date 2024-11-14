#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll t,n,x,a[N];
void Solve(){
    cin>>n;
    a[0]=0;
    ll ans=0,ans1=-inf,ans2=-inf;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]>=0) ans+=a[i];
        ans2=max(ans2,a[i]);
        if (a[i-1]>=0) a[i]+=a[i-1];
        ans1=max(ans1,a[i]);
    }
    (ans2>=0) ? cout<<ans<<" "<<ans1<<endl : cout<<ans2<<" "<<ans1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

