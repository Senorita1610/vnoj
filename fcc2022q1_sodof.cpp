#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n;
void Solve(){
    cin>>n;
    if (n<=1) cout<<1<<endl;
    else if (n==2) cout<<2<<endl;
    else if (n<=4) cout<<6<<endl;
    else if (n==5) cout<<3<<endl;
    else cout<<9<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

