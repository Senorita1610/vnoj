#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=55,inf=1e+18;
ll n,ans=inf,a[N],x[20]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47},y[20];
void Check(){
    ll s=1;
    for (ll i=1;i<=15;i++)
        if (y[i]==1) s*=x[i];
    for (ll i=1;i<=n;i++)
        if (__gcd(a[i],s)==1) return;
    ans=min(ans,s);
}
void Try(ll i){
    for (ll j=0;j<=1;j++){
        y[i]=j;
        if (i<15) Try(i+1);
        else Check();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    Try(1);
    cout<<ans;
}

