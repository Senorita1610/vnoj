#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,k,a[N],l=-inf,r=0;
ll Check(ll md){
    ll x=0,s=1;
    for (ll i=1;i<=n;i++){
        if (x+a[i]<=md) x+=a[i];
        else{
            x=a[i];
            s++;
        }
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        l=max(l,a[i]);
        r+=a[i];
    }
    while (l<r){
        ll md=(l+r)/2;
        if (Check(md)<=k) r=md;
        else if (Check(md)>k) l=md+1;
    }
    cout<<l;
}

