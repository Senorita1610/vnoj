#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
ll n,ans=0;
string s;
void Solve(){
    cin>>s;
    for (ll i=0;i<s.size();i++)
        if (s[i]=='A') ans+=4;
        else if (s[i]=='K') ans+=3;
        else if (s[i]=='Q') ans+=2;
        else if (s[i]=='J') ans+=1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while (n--) Solve();
    cout<<ans;
}

