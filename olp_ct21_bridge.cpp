#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t;
const ll inf=1e9+7;
void Solve(){
    ll ans=1;
    string a,b;
    cin>>a>>b;
    for (ll i=0;i<a.size();i++)
        if (a[i]=='O' && b[i]=='O'){
            cout<<0<<endl;
            return;
        }
        else if (a[i]=='X' && b[i]=='X') ans=(ans*2)%inf;
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

