#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
string s,m="0";
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>s;
        m=max(m,s);
    }
    if (m[0]!='0') cout<<m<<endl;
    else{
        cout<<1;
        for (ll i=1;i<m.size();i++) cout<<0;
        cout<<endl;
    }
    for (ll i=0;i<m.size();i++) cout<<9;
}

