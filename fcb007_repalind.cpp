#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,k;
string s;
string Check(string s){
    for (ll i=0;i<s.size()/2;i++)
        if (s[i]!=s[s.size()-i-1]) return "NO";
    return "YES";
}
void Solve(){
    cin>>s>>k;
    cout<<Check(s)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

