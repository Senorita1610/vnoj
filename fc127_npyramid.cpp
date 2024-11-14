#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,v;
void Solve(){
    cin>>n>>v;
    for (ll i=1;i<=n;i++){
        for (ll j=1;j<=i;j++)
            (j==i) ? cout<<v<<" " : cout<<0<<" ";
        cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

