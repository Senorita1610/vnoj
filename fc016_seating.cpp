#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m,k,x,y,ans;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    ans=n*(m-1);
    for (ll i=1;i<=k;i++){
        cin>>x>>y;
        mp[m*(x-1)+y]=1;
        ans-=(y>1)*(mp[m*(x-1)+y-1]==0);
        ans-=(y<m)*(mp[m*(x-1)+y+1]==0);
    }
    cout<<ans;
}

