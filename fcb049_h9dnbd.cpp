#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,a,ans1=0,ans2=0;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>a;
        mp[a]++;
        if (mp[a]==k){
            ans1++;
            ans2+=a;
        }
    }
    cout<<ans1<<" "<<ans2;
}

