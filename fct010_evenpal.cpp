#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t;
string s;
void Solve(){
    cin>>s;
    for (ll i=0;i<s.size()-1;i++)
        if (s[i]==s[i+1]){
            cout<<"YES"<<endl;
            return;
        }
    cout<<"NO"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

