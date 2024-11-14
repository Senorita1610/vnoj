#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll n,ans=0,d=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    for (ll i=1;i<s.size();i++)
        if (s[i]==s[i-1]) d++;
        else{
            ans+=d*(d+1)/2;
            d=0;
        }
    cout<<ans+d*(d+1)/2;
}

