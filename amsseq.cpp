#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=10005,inf=1e+18;
ll n,k,ans=0,a[N]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        ll o=i-k,d=-inf;
        if (o<0) o=0;
        for (ll j=o;j<i;j++) d=max(d,a[j]);
        a[i]+=d;
        ans=max(ans,a[i]);
    }
    cout<<ans;
}

