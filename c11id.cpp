#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000000,MOD=1e9+7;
ll n,ans=1,a[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (ll i=1;i<=n;i++)
        ans=(ans*(a[i]-i+1))%MOD;
    cout<<ans;
}

