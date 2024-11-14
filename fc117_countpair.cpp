#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll ans=0,x=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=0;i<s.size();i++)
        if (s[i]=='2') ans+=x;
        else if (s[i]=='1') x++;
    cout<<ans;
}

