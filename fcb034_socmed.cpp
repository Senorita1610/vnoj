#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string x,p;
const ll N=105;
ll n,m,a[N]={};
unordered_map <string,ll> cnt;
unordered_map <string,string> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>x>>p;
        mp[x]=p;
        cnt[x]=i;
    }
    cin>>m;
    while (m--){
        cin>>x>>p;
        if (p==mp[x]) a[cnt[x]]++;
    }
    for (ll i=1;i<=n;i++) cout<<a[i]<<" ";
}

