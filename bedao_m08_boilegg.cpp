#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,x;
void Solve(){
    cin>>n;
    x=(ll)sqrt(n);
    (x*x==n) ? cout<<1<<endl : cout<<0<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

