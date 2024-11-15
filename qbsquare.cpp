#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005,inf=1e+18;
ll n,m,a[N][N],f[N][N],ans=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++){
            cin>>a[i][j];
            if (i==1 || j==1) f[i][j]=1;
            else if (a[i][j]==a[i-1][j] && a[i][j]==a[i][j-1] && a[i][j]==a[i-1][j-1]) f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
            else f[i][j]=1;
            ans=max(ans,f[i][j]);
        }
    cout<<ans;
}

