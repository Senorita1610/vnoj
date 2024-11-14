#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,a,b,c;
void Solve(){
    cin>>a>>b>>c;
    cout<<max(b-a-1,c-b-1)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

