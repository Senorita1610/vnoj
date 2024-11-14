#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD=1e9+7;
string s;
ll ans=1,d=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=1;i<s.size();i++)
        if (s[i]==s[i-1]) d++;
        else{
            ans=(ans*d)%MOD;
            d=1;
        }
    cout<<(ans*d)%MOD;
}

