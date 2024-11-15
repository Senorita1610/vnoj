#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=505;
ll n,m;
char a[N][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            cin>>a[i][j];
    for (ll i=1;i<n;i++)
        for (ll j=1;j<m;j++)
            if (a[i][j]!=a[i+1][j] && a[i][j]!=a[i][j+1] && a[i+1][j]!=a[i+1][j+1] && a[i][j+1]==a[i+1][j+1]){
                cout<<"YES";
                return 0;
            }
    cout<<"NO";
}

