#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005;
ll n,k,a[N][N],ans=-1e+18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=0;i<=n;i++){
        a[0][i]=0;
        a[i][0]=0;
    }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++){
            cin>>a[i][j];
            a[i][j]+=(a[i-1][j]+a[i][j-1]-a[i-1][j-1]);
        }
    for (ll i=k;i<=n;i++)
        for (ll j=k;j<=n;j++)
            ans=max(ans,a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]);
    cout<<ans;
}

