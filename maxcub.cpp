#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=35;
ll t,n,ans,a[N][N][N];
void Solve(){
    cin>>n;
    ans=-1e+18;
    for (ll i=0;i<=n;i++)
        for (ll j=0;j<=n;j++){
            a[0][i][j]=0;
            a[i][0][j]=0;
            a[i][j][0]=0;
        }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++)
            for (ll k=1;k<=n;k++){
                cin>>a[i][j][k];
                a[i][j][k]=a[i][j][k]+a[i-1][j][k]+a[i][j-1][k]+a[i][j][k-1]-a[i][j-1][k-1]-a[i-1][j][k-1]-a[i-1][j-1][k]+a[i-1][j-1][k-1];
            }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++)
            for (ll k=1;k<=n;k++)
                for (ll l=1;l<=min(min(i,j),k);l++)
                    ans=max(ans,a[i][j][k]-a[i-l][j][k]-a[i][j-l][k]-a[i][j][k-l]+a[i-l][j-l][k]+a[i][j-l][k-l]+a[i-l][j][k-l]-a[i-l][j-l][k-l]);
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

