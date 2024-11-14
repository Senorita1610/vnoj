#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,ans=0;
string s;
unordered_map <string,ll> mp;
ll Check(string s){
    if (s[0]>='0' && s[0]<='9'){
        ll o=0;
        for (ll i=0;i<s.size();i++) o=o*10+s[i]-48;
        return o<18;
    }
    return mp[s];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mp["ABSINTH"]=1,mp["TEQUILA"]=1,mp["VODKA"]=1,mp["WHISKEY"]=1,mp["WINE"]=1,mp["BEER"]=1,mp["BRANDY"]=1,mp["CHAMPAGNE"]=1,mp["GIN"]=1,mp["RUM"]=1,mp["SAKE"]=1;
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>s;
        ans+=Check(s);
    }
    cout<<ans;
}

