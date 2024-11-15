#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,k,a[N],ans=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    a[0]=0;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
        if (i>=k) ans=max(ans,a[i]-a[i-k]);
    }
    cout<<ans;
}

