#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,a[N],b[N];
ll Find(ll x){
    ll l=0,r=n;
    while (l<r){
        ll md=(l+r)/2;
        if (b[md+1]>=x) r=md;
        else l=md+1;
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    b[0]=0;
    sort(b+1,b+n+1);
    for (ll i=1;i<=n;i++) cout<<Find(a[i])<<" ";
}

