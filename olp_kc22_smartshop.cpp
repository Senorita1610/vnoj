#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=500005,A=1e+9,inf=1e+18;
ll n,k,x,y,a[N],d=0;
unordered_map <ll,ll> mp;
void Build(){
    for (ll i=1;i<=A;i*=2) mp[i]=1;
    for (ll i=1;i<=A;i*=3) mp[i]=1;
    for (ll i=1;i<=A;i*=5) mp[i]=1;
}
ll Get(ll x){
    ll l=0,r=n;
    while (l<r){
        ll md=(l+r)/2;
        if (a[md+1]>x) r=md;
        else l=md+1;
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    Build();
    for (ll i=1;i<=n;i++){
        cin>>x;
        if (mp[x]==1){
            d++;
            a[d]=x;
        }
    }
    n=d;a[0]=-inf;
    sort(a+1,a+n+1);
    while (k--){
        cin>>x>>y;
        cout<<Get(y)-Get(x-1)<<endl;
    }
}

