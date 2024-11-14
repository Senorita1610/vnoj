#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll ans=0;
unordered_map <char,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=0;i<s.size();i++){
        ans+=mp[s[i]]==0;
        mp[s[i]]=1;
    }
    cout<<ans;
}

