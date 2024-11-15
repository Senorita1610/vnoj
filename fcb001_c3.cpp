#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x,a,ans=0;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>x;
    for (ll i=1;i<=n;i++){
        cin>>a;
        mp[a]++;
        ans+=mp[x-a*a];
    }
    cout<<ans;
}

