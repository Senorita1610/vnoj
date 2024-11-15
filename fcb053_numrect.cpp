#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,m;
void Solve(){
    cin>>n>>m;
    cout<<n*m*(n+1)*(m+1)/4<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

