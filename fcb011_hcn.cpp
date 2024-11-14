#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000;
ll n,m,ans=0,a[N+5][N+5],x[N+5][N+5],fi[4]={-1,1,0,0},fj[4]={0,0,-1,1};
void DFS(ll i, ll j){
    x[i][j]=0;
    for (ll k=0;k<4;k++){
        ll i1=i+fi[k],j1=j+fj[k];
        if (x[i1][j1]) DFS(i1,j1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++){
            cin>>a[i][j];
            x[i][j]=a[i][j];
        }
    for (ll i=1;i<=n;i++){x[i][0]=0;x[i][m+1]=0;}
    for (ll i=1;i<=m;i++){x[0][i]=0;x[n+1][i]=0;}
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            if (x[i][j]){
                ans++;
                DFS(i,j);
            }
    cout<<ans;
}

