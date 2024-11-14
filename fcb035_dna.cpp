#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=0;i<s.size();i++)
        if (s[i]=='A') s[i]='T';
        else if (s[i]=='T') s[i]='A';
        else if (s[i]=='G') s[i]='C';
        else if (s[i]=='C') s[i]='G';
    for (ll i=s.size()-1;i>=0;i--) cout<<s[i];
}

