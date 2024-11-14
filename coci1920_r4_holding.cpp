#pragma GCC optimize("O2,unroll-loops,inline")
#pragma GCC target("avx2,bmi,bmi2")
#include<bits/stdc++.h>
#define ll int
#define ld long double
#define pb push_back
#define prec fixed<<setprecision
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pll pair<ll,ll>
#define open(name) if(fopen(name".inp", "r")){freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);}
using namespace std;
const int maxN=103;
const int mod=998244353;
ll n,l,r,z,a[maxN],f[102][102][2503],g[102][102][2503];
void Enter(){
    cin>>n>>l>>r>>z;
    z=min(z,n*n/4);
    ll res=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(l<=i&&i<=r)res+=a[i];
    }
    //f[i][j][k]=so tien giam bot lon nhat khi thay [L,j] bang cac ptu trong [1,i] voi chi phi k, swap(a[i],a[j])
    // tuong tu voi g
    for(int i=1;i<l;i++)for(int j=l;j<=r;j++)for(int k=0;k<=z;k++){
        f[i][j][k]=max(f[i][j-1][k],f[i-1][j][k]);
        if(k>=j-i)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k-j+i]+a[j]-a[i]);
    }
    for(int i=n;i>r;i--)for(int j=r;j>=l;j--)for(int k=0;k<=z;k++){
        g[j][i][k]=max(g[j+1][i][k],g[j][i+1][k]);
        if(k>=i-j)g[j][i][k]=max(g[j][i][k],g[j+1][i+1][k+j-i]+a[j]-a[i]);
    }
    ll x=max(f[l-1][r][z],g[l][r+1][z]);
    for(int i=l;i<=r;i++)for(int k=0;k<=z;k++)x=max(x,f[l-1][i][k]+g[i+1][r+1][z-k]);
    cout<<res-x;
}
//amogus
signed main(){
    open("DEBT");
    cin.tie(nullptr);ios_base::sync_with_stdio(NULL);
    //ll t=1;cin>>t;while(t--)
    Enter();
}

