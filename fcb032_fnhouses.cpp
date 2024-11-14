#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000;
ll n,m,ans=0,ans1=0;
char a[N+5][N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++) a[i][0]='.';
    for (ll i=1;i<=m;i++) a[0][i]='.';
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++){
            cin>>a[i][j];
            if (a[i][j]=='#') ans+=(a[i][j-1]=='#')+(a[i-1][j-1]=='#')+(a[i-1][j]=='#')+(a[i-1][j+1]=='#');
        }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            if (a[i][j]=='.') ans1=max(ans1,(ll)((a[i][j-1]=='#')+(a[i-1][j-1]=='#')+(a[i-1][j]=='#')+(a[i-1][j+1]=='#')+(a[i][j+1]=='#')+(a[i+1][j+1]=='#')+(a[i+1][j]=='#')+(a[i+1][j-1]=='#')));
    cout<<ans+ans1;
}

