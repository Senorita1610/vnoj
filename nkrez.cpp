#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=10000;
ll n,x[N+5]={};
pair <ll,ll> a[N+5];
bool comp(const pair <ll,ll> a, const pair <ll,ll> b){
    return (a.second<b.second || (a.second==b.second && a.first<b.first));
}
ll Find(ll t, ll l, ll r){
    while (l<r){
        ll md=(l+r)/2;
        if (a[md+1].second<=t) l=md+1;
        else r=md;
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1,comp);
    a[0].second=0;
    for (ll i=1;i<=n;i++)
        x[i]=max(x[i-1],x[Find(a[i].first,0,i-1)]+a[i].second-a[i].first);
    cout<<x[n];
}

