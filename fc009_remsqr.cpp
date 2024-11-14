#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100;
ll n,m,ans=0,x[N+5][N+5],fi[4]={-1,1,0,0},fj[4]={0,0,-1,1};
char a[N+5][N+5];
void DFS(ll i, ll j){
    x[i][j]=1;
    for (ll k=0;k<4;k++)
        if (x[i+fi[k]][j+fj[k]]==0) DFS(i+fi[k],j+fj[k]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++){
            cin>>a[i][j];
            (a[i][j]=='#') ? x[i][j]=0 : x[i][j]=-1;
        }
    for (ll i=1;i<=n;i++){x[i][0]=-1;x[i][m+1]=-1;}
    for (ll i=1;i<=m;i++){x[0][i]=-1;x[n+1][i]=-1;}
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            if (x[i][j]==0){
                ans++;
                DFS(i,j);
            }
    cout<<ans;
}

