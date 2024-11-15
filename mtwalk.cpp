#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=105,inf=1e+18;
ll n,a[N][N],o[N][N],mi=inf,ma=-inf,ans=inf;
void Try(ll i, ll j, ll x, ll y){
    o[i][j]=1;
    if (o[i-1][j]==0 && i>1 && a[i-1][j]>=x && a[i-1][j]<=y) Try(i-1,j,x,y);
    if (o[i+1][j]==0 && i<n && a[i+1][j]>=x && a[i+1][j]<=y) Try(i+1,j,x,y);
    if (o[i][j-1]==0 && j>1 && a[i][j-1]>=x && a[i][j-1]<=y) Try(i,j-1,x,y);
    if (o[i][j+1]==0 && j<n && a[i][j+1]>=x && a[i][j+1]<=y) Try(i,j+1,x,y);
}
ll Check(ll j){
    for (ll i=a[1][1];i>=mi;i--){
        for (ll i1=1;i1<=n;i1++)
            for (ll j1=1;j1<=n;j1++)
                o[i1][j1]=0;
        Try(1,1,i,j);
        if (o[n][n]==1){
            ans=min(ans,j-i);
            return 1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++){
            cin>>a[i][j];
            mi=min(mi,a[i][j]);
            ma=max(ma,a[i][j]);
        }
    for (ll i=a[1][1];i<=ma;i++) Check(i);
    cout<<ans;
}

