#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000;
ll n,m,ans=0,a[N+5][N+5],x[N+5]={},y[N+5]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++){
            cin>>a[i][j];
            x[i]=max(x[i],a[i][j]);
            y[j]=max(y[j],a[i][j]);
        }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            ans+=a[i][j]*(a[i][j]!=x[i] && a[i][j]!=y[j]);
    cout<<ans;
}

