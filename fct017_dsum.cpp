#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=0;i<s.size();i++) ans=ans+int(s[i])-48;
    cout<<ans;
}

