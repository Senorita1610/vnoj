#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll X=1000005,inf=1e+18;
ll n,x,o,a[X]={},b[X],ans=inf;
void SangNt(){
    a[1]=1;
    ll i=1;
    while (i<=sqrt(X)){
        while (a[i]==1) i++;
        for (ll j=2;j<=X/i;j++)
            a[i*j]=1;
        i++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>x;
    SangNt();
    for (ll i=1;i<=n;i++){
        cin>>o;
        if (o>=2 && o<=x) b[i]=(a[o]+1)%2;
        else b[i]=0;
    }
    b[0]=0;
    for (ll i=1;i<=n;i++) b[i]+=b[i-1];
    for (ll i=b[n];i<=n;i++) ans=min(ans,b[n]-b[i]+b[i-b[n]]);
    cout<<ans;
}

