#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105;
ll t,n,a[N];
void Solve(){
    cin>>n;
    vector <ll> v;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<n;i++)
        for (ll j=i+1;j<=n;j++)
            v.push_back(__gcd(a[i],a[j]));
    sort(v.begin(),v.end(),greater<ll>());
    cout<<v[1]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

