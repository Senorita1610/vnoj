#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=400005;
ll n,a[2*N],b[2*N],x[2*N],ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=2*n;i++){
        cin>>a[i]>>b[i];
        x[i]=a[i]-b[i];
        ans+=a[i];
    }
    sort(x+1,x+2*n+1,greater<ll>());
    for (ll i=1;i<=n;i++) ans-=x[i];
    cout<<ans;
}

