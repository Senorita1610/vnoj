#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=500005;
ll n,a[N],ans=0,d=1;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        while (mp[a[i]]>2){
            mp[a[d]]--;
            d++;
        }
        ans+=(i-d+1);
    }
    cout<<ans;
}

