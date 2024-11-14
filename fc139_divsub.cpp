#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll n,p,ans=0,x=0,y=1;
unordered_map <ll,ll> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>p>>s;
    if (10%p==0){
        for (ll i=0;i<s.size();i++)
            ans+=(i+1)*((int(s[i])-48)%p==0);
        cout<<ans;
        return 0;
    }
    mp[0]=1;
    for (ll i=s.size()-1;i>=0;i--){
        x=(x+(int(s[i])-48)*y)%p;
        y=(y*10)%p;
        ans+=mp[x];
        mp[x]++;
    }
    cout<<ans;
}

