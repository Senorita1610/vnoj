#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD=1e9+7;
ll t,a,b;
void Solve(){
    cin>>a>>b;
    cout<<(((b*b)%MOD)*a-a+1)%MOD<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

