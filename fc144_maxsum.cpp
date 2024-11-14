#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,a[N],ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<n;i++) cin>>a[i];
    a[0]=inf,a[n]=inf;
    for (ll i=1;i<=n;i++) ans+=min(a[i-1],a[i]);
    cout<<ans;
}

