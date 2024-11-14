#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,a,ans=0;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>a;
        mp[a%k]++;
    }
    for (ll i=1;i<(k+1)/2;i++) ans+=max(mp[i],mp[k-i]);
    if (k%2==0) ans+=(mp[k/2]!=0);
    ans+=(mp[0]!=0);
    cout<<ans;
}

