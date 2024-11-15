#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,a[N],ans=0,ans1=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    for (ll i=1;i<n;i++){
        ll x=ans;
        (a[i]>0) ? x-=2 : x+=2;
        (a[i+1]>0) ? x-=2 : x+=2;
        ans1=max(ans1,x);
    }
    cout<<ans1;
}

