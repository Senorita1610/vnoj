#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,ans=0;
ll Cp(ll n){
    ll x=(ll)sqrt(n);
    return (x*x==n) ? 1 : 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=sqrt(n);i++)
        ans+=Cp(n-i*i);
    cout<<ans;
}

