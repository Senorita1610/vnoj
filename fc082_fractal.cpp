#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,m;
char a[5][5],x[250][250],y[250][250];
void Try(){
    for (ll i=1;i<=m*n;i++)
        for (ll j=1;j<=m*n;j++)
            (a[(i+m-1)/m][(j+m-1)/m]=='*') ? y[i][j]='*' : y[i][j]=x[i%m+m*(i%m==0)][j%m+m*(j%m==0)];
    m*=n;
    for (ll i=1;i<=m;i++)
        for (ll j=1;j<=m;j++)
            x[i][j]=y[i][j];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++){
            cin>>a[i][j];
            x[i][j]=a[i][j];
        }
    m=n;
    for (ll i=1;i<k;i++) Try();
    for (ll i=1;i<=m;i++){
        for (ll j=1;j<=m;j++)
            cout<<x[i][j];
        cout<<endl;
    }
}

