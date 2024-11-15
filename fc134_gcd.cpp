#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,m,a[N],b[N],ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+n+1);
    for (ll i=1;i<n;i++) ans=__gcd(ans,a[i+1]-a[i]);
    for (ll i=1;i<=m;i++) cout<<__gcd(ans,a[1]+b[i])<<" ";
}

