#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005, inf=1e+18;
ll n,a[N],x[N],ans=-inf;
unordered_map <ll,ll> mp,cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    x[0]=0;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        x[i]=x[i-1]+a[i];
    }
    for (ll i=1;i<=n;i++){
        if (mp[a[i]]==1) ans=max(ans,x[i]-x[cnt[a[i]]-1]);
        if (mp[a[i]]==0){
            mp[a[i]]=1;
            cnt[a[i]]=i;
        }
        else if (mp[a[i]]==1)
            if (x[i]<x[cnt[a[i]]]) cnt[a[i]]=i;
    }
    cout<<ans;
}

