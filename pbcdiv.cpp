#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,a,b;
ll Solve(ll n){
    return n/12-n/60+n/30-n/60;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--){
        cin>>a>>b;
        cout<<Solve(b)-Solve(a-1)<<endl;
    }
}

