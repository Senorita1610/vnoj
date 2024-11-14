#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=2000005,inf=1e+18;
ll n,a[25],b[25],x[N]={},ans=-inf;
void SangNt(){
    x[1]=1;
    ll i=1;
    while (i<=sqrt(N)){
        while (x[i]==1) i++;
        for (ll j=2;j<=N/i;j++)
            x[i*j]=1;
        i++;
    }
}
void Check(){
    ll s1=0,s2=0;
    for (ll i=1;i<=n;i++)
        (b[i]==0) ? s1+=a[i] : s2+=a[i];
    if (x[abs(s1-s2)]==0) ans=max(ans,abs(s1-s2));
}
void Try(ll i){
    for (ll j=0;j<=1;j++){
        b[i]=j;
        if (i<n) Try(i+1);
        else Check();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SangNt();
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    Try(1);
    (ans==-inf) ? cout<<-1 : cout<<ans;
}

