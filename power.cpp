#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,a,b,d=0;
void Solve(){
    d++;
    cin>>a>>b;
    for (ll i=40;i>=1;i--){
        ll x=2;
        while (pow(x,i)<a) x++;
        if (pow(x,i)<=b){
            cout<<"Case #"<<d<<": "<<i<<endl;
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

