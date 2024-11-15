#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n=0;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=0;i<s.size();i++) n=n+int(s[i])-48;
    cout<<s<<(10-n%10)%10;
}

