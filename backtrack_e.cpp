#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=15;
ll t,n,m,ans,a[N],x[N];
void Check(){
    ll s=0,d=1;
    for (ll i=n;i>=1;i--)
        if (x[i]==3) d=(d*a[i])%m;
        else{
            (x[i]==1) ? s=(s+d*a[i])%m : s=(s-d*a[i])%m;
            d=1;
        }
    ans+=s==0;
}
void Try(ll i){
    for (ll j=1;j<=3;j++){
        x[i]=j;
        if (i<n) Try(i+1);
        else Check();
    }
}
void Solve(){
    cin>>n>>m;
    ans=0;
    for (ll i=1;i<=n;i++) cin>>a[i];
    Try(2);
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

