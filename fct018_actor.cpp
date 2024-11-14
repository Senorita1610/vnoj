#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll r,t,n,a,b,c,o=0;
void Solve(){
    cin>>n>>a>>b>>c;
    (r==1) ? cout<<max(o,a+b+c-2*n)<<endl : cout<<min(a,min(b,c))<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>r>>t;
    while (t--) Solve();
}

