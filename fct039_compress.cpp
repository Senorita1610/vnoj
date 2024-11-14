#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string s;
ll Check(ll x){
    for (ll i=0;i<s.size();i++)
        if (s[i]!=s[i%x]) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=1;i<=s.size();i++)
        if (s.size()%i==0 && Check(i)==1){
            cout<<s.size()/i;
            for (ll j=0;j<i;j++) cout<<s[j];
            return 0;
        }
}

