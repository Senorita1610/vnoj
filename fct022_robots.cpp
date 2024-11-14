#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100000;
ll n,ans=1,x[N+5];
pair <ll,ll> a[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        a[i].first=a[i].first-a[i].second;
        a[i].second=a[i].first+2*a[i].second;
    }
    sort(a+1,a+n+1);
    x[1]=1;
    for (ll i=2;i<=n;i++){
        x[i]=x[i-1]+(a[i].first>=a[i-1].second);
        if (i>1 && a[i].first<a[i-1].second) a[i].second=min(a[i].second,a[i-1].second);
        ans=max(ans,x[i]);
    }
    cout<<ans;
}

