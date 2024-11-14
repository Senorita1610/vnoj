#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll S=200005;
ll n,x,mp[S]={};
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>n;
    for (ll i=1;i<=n;i++){
        cin>>x;
        mp[x]++;
    }
    for (ll i=1;i<=s.size()/2;i++){
        mp[i]+=mp[i-1];
        mp[i]%=2;
        if (mp[i]==1) swap(s[i-1],s[s.size()-i]);
    }
    cout<<s;
}

