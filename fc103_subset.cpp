#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,x,ans=0;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>x;
        mp[x%k]++;
    }
    for (ll i=0;i<=k/2;i++)
        ans+=max(mp[i],mp[k-i]);
    if (mp[0]>1) ans-=(mp[0]-1);
    if (mp[k/2]>1 && k%2==0) ans-=(mp[k/2]-1);
    cout<<ans;
}

