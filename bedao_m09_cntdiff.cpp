#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=300005;
ll n,k,a[N],d=1,e=0,ans=0;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        if (mp[a[i]]==0) e++;
        mp[a[i]]++;
        if (i-d+1>k){
            mp[a[d]]--;
            if (mp[a[d]]==0) e--;
            d++;
        }
        if (i-d+1==k) ans=max(ans,e);
    }
    cout<<ans;
}

