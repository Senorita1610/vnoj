#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,a,b,ans=0;
void Solve(){
    cin>>a>>b;
    ans+=(b+a)*(b-a+1)/2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
    cout<<ans;
}

