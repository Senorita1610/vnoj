#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=30005,inf=1e+18;
ll n,x,f[N],ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) f[i]=inf;
    for (ll i=1;i<=n;i++){
        cin>>x;
        ll z=lower_bound(f+1,f+n+1,x)-f;
        f[z]=x;
        ans=max(ans,z);
    }
    cout<<ans;
}

