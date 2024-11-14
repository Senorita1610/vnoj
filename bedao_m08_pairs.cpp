#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=10000005;
ll n,m,a[N]={},mp[N]={},d=0,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++) a[i]=i;
    for (ll i=2;i*i<=n;i++)
        for (ll j=i*i;j<=n;j+=i*i)
            a[j]=j/(i*i);
    for (ll i=n;i>=1;i--){
        while (i*(d+1)<=m && d+1<i){
            d++;
            mp[a[d]]++;
        }
        while (d>=i){
            mp[a[d]]--;
            d--;
        }
        ans+=mp[a[i]];
    }
    cout<<ans;
}

