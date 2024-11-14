#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005,inf=1e+18;
ll n,a[N],ans=0,t=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a[n+1]=inf;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=n;i>=1;i--){
        a[i]=max(t,min(a[i],a[i+1]-1));
        ans+=a[i];
    }
    cout<<ans;
}

