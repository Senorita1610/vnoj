#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll n,d=0,ans1=0,ans2=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    for (ll i=0;i<n;i++) d+=s[i]=='0';
    for (ll i=0;i<d;i++) ans1+=s[i]=='1';
    for (ll i=n-1;i>=n-d;i--) ans2+=s[i]=='1';
    cout<<min(ans1,ans2);
}

