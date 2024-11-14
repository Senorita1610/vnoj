#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005;
ll n,m,x[N][N],a[N][N],o=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++){a[i][m+1]=-1e+10;x[i][m+1]=1e+10;}
    for (ll j=1;j<=m;j++){a[n+1][j]=-1e+10;x[n+1][j]=1e+10;}
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            cin>>a[i][j];
    x[n][m]=0;
    for (ll i=n;i>=1;i--)
        for (ll j=m;j>=1;j--)
            if (i!=n || j!=m)
                x[i][j]=min(max(x[i][j+1]-a[i][j],a[i][j+1]-a[i][j]+1),max(x[i+1][j]-a[i][j],a[i+1][j]-a[i][j]+1));
    cout<<max(a[1][1]+1,x[1][1]);
}

