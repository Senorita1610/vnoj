#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m,ans=0;
void Solve(){
    char k;
    ll d=0,s=0;
    for (ll i=1;i<=m;i++){
        cin>>k;
        s+=d;
        if (k!='.') d=(d+1)%2;
    }
    ans+=s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++) Solve();
    cout<<ans;
}

