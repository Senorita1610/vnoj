#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,x;
void Solve(){
    cin>>n;
    x=cbrtl(n);
    (x*x*x==n) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

