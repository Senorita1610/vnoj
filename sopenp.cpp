#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1048576;
ll n,l,u,d1=1,d2=1,m1=0,m2=0,ans=0,a[N+5],x[N+5],y[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l>>u;
    for (ll i=1;i<=n;i++) cin>>a[i];
    unordered_map <ll,ll> mp1,mp2;
    for (ll i=1;i<=n;i++){
        m1+=mp1[a[i]]==0;
        m2+=mp2[a[i]]==0;
        mp1[a[i]]++;
        mp2[a[i]]++;
        while (m1>u){
            mp1[a[d1]]--;
            m1-=mp1[a[d1]]==0;
            d1++;
        }
        while (m2>l-1){
            mp2[a[d2]]--;
            m2-=mp2[a[d2]]==0;
            d2++;
        }
        ans+=d2-d1;
    }
    cout<<ans;
}

