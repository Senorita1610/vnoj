#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,a[N],x[N],y[N],ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    x[0]=-inf;
    y[n+1]=-inf;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        x[i]=max(x[i-1],a[i]);
    }
    for (ll i=n;i>=1;i--){
        y[i]=max(y[i+1],a[i]);
        ans+=(min(x[i],y[i])-a[i]);
    }
    cout<<ans;
}

