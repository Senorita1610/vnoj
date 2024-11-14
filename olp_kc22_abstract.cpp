#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005;
ll n,m,ans=0,a[N][N];
struct Node{
    ll a,b,c,d;
};
Node x[N][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            cin>>a[i][j];
    for (ll i=0;i<=n+1;i++){
        x[i][0].b=0;
        x[i][m+1].d=0;
    }
    for (ll j=0;j<=m+1;j++){
        x[0][j].a=0;
        x[n+1][j].c=0;
    }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++){
            x[i][j].a=max(a[i][j],x[i-1][j].a);
            x[i][j].b=max(a[i][j],x[i][j-1].b);
        }
    for (ll i=n;i>=1;i--)
        for (ll j=m;j>=1;j--){
            x[i][j].c=max(a[i][j],x[i+1][j].c);
            x[i][j].d=max(a[i][j],x[i][j+1].d);
        }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            if (a[i][j]>x[i-1][j].a || a[i][j]>x[i][j-1].b || a[i][j]>x[i+1][j].c || a[i][j]>x[i][j+1].d)
                ans++;
    cout<<ans;
}

