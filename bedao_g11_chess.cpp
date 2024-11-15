#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m,k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    if (k>min(n,m)){
        cout<<n+m+k;
        return 0;
    }
    for (ll i=1;i<=k;i++) cout<<i<<" "<<i<<endl;
}

