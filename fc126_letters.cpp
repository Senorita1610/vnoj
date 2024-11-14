#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    if (s[0]=='?') s[0]='a';
    if (s[n-1]=='?') s[n-1]='b';
    cout<<s[n-1]-s[0];
}

