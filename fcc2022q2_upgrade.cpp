#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,a,ans;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    ans=n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        mp[a]++;
        while (mp[a]>=k){
            ll d=mp[a]/k;
            mp[a]-=d*k;
            mp[a+1]+=d;
            ans-=d*(k-1);
            a++;
        }
    }
    cout<<ans;
}

