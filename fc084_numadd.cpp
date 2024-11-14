#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll t,n,a;
void Solve(){
    cin>>n;
    ll ans=0,m=-inf;
    for (ll i=1;i<=n;i++){
        cin>>a;
        m=max(m,a);
        ans=__gcd(ans,a);
    }
    cout<<(m/ans-n)%2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

