#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005,inf=1e+18;
ll n,a[N],ans=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        if (i>2) ans=max(ans,a[i]-a[i-2]);
    }
    cout<<ans;
}

