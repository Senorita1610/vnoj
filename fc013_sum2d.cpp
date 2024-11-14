#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200;
ll n,m,q,x,y,z,t,a[N+5][N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>q;
    for (ll i=0;i<=n;i++) a[i][0]=0;
    for (ll i=0;i<=m;i++) a[0][i]=0;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++){
            cin>>a[i][j];
            a[i][j]+=(a[i-1][j]+a[i][j-1]-a[i-1][j-1]);
        }
    while (q--){
        cin>>x>>y>>z>>t;
        cout<<a[z][t]-a[z][y-1]-a[x-1][t]+a[x-1][y-1]<<endl;
    }
}

