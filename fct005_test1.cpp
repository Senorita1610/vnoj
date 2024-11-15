#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=10005,inf=1e+18;
ll n,x,mp[N]={},d=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>x;
        mp[x]++;
    }
    for (ll i=1;i<=N-5;i++) d=max(d,mp[i]);
    for (ll i=1;i<=N-5;i++)
        if (mp[i]==d){
            cout<<i;
            return 0;
        }
}

