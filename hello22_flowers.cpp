#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=2000005;
ll n,m,ans=0,o=1,a[N];
void SangNt(){
    for (ll i=1;i<=N;i++) a[i]=1;
    a[1]=0;
    ll i=1;
    while (i<=sqrt(N)){
        while (a[i]==0) i++;
        for (ll j=2;j<=N/i;j++)
            a[i*j]=0;
        i++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    SangNt();
    for (ll i=1;i<=n+m;i++)
        if (a[i]==1)
            ans+=(min(n,i-1)-max(o,i-m)+1);
    cout<<ans;
}

