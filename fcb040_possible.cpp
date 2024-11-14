#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,s;
void Solve(){
    cin>>n>>s;
    n=n*(n+1)/2;
    ((n-s)%2==0 && s<=n && s>=-n) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

