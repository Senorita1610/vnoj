#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=505,inf=1e+18;
ll n,a[N][N],ans=inf;
void Check(ll i, ll j){
    ll x1,x2,x3,x4;
    x1=a[i][j];
    x2=a[n][j]-a[i][j];
    x3=a[i][n]-a[i][j];
    x4=a[n][n]-a[n][j]-a[i][n]+a[i][j];
    ans=min(ans,max(max(x1,x2),max(x3,x4))-min(min(x1,x2),min(x3,x4)));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("Chiadat.inp","r",stdin);
    freopen ("Chiadat.out","w",stdout);
    cin>>n;
    for (ll i=0;i<=n;i++){
        a[i][0]=0;
        a[0][i]=0;
    }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++){
            cin>>a[i][j];
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
        }
    for (ll i=1;i<n;i++)
        for (ll j=1;j<n;j++)
            Check(i,j);
    cout<<ans;
}

