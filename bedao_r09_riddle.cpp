#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll d=0,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=0;i<s.size()-1;i++)
        ans+=(s[i]==s[i+1]);
    for (ll i=1;i<s.size();i++)
        if (s[i]!=s[i-1] && i>d+1){
            ans+=(s[i]==s[d]);
            d=i-1;
        }
    cout<<ans;
}

