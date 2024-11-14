#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=305;
ll n,m,a[N],d=0;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++)
        if (mp[a[i]]==0 && a[i]<=m){
            mp[a[i]]=1;
            d++;
        }
    for (ll i=1;i<n;i++)
        for (ll j=i+1;j<=n;j++)
            if (mp[a[i]+a[j]]==0 && a[i]+a[j]<=m){
                d++;
                mp[a[i]+a[j]]=1;
            }
    for (ll i=1;i<n-1;i++)
        for (ll j=i+1;j<n;j++)
            for (ll z=j+1;z<=n;z++)
                if (a[i]+a[j]+a[z]<=m && mp[a[i]+a[j]+a[z]]==0){
                    d++;
                    mp[a[i]+a[j]+a[z]]=1;
                }
    cout<<d;
}

