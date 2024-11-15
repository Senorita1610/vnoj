#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005,K=55,inf=1e+18;
ll n,k,a[N],x[N][K];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        a[i]%=k;
    }
    for (ll i=1;i<k;i++) x[0][i]=-inf;
    for (ll i=1;i<=n;i++)
        for (ll j=0;j<k;j++)
            x[i][j]=max(x[i-1][j],x[i-1][(j-a[i]+k)%k]+1);
    cout<<x[n][0];
}

