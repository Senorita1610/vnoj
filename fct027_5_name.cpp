#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t;
string s;
void Solve(){
    getline(cin,s);
    while (s[0]==' ') s.erase(0,1);
    while (s[s.size()-1]==' ') s.erase(s.size()-1,1);
    for (ll i=s.size()-1;i>0;i--)
        if (s[i]==' ' && s[i-1]==' ') s.erase(i,1);
    for (ll i=0;i<s.size();i++)
        if (s[i]>='A' && s[i]<='Z') s[i]+=32;
    for (ll i=0;i<s.size();i++)
        if (s[i]==' ') s[i+1]-=32;
    s[0]-=32;
    cout<<s<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    cin.ignore();
    while (t--) Solve();
}

