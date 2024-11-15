#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200000;
ll a,b,ans=0,x[N+5];
void SangNt(){
    for (ll i=1;i<=N;i++) x[i]=1;
    x[1]=0;
    ll i=1;
    while (i<=sqrt(N)){
        while (x[i]==0) i++;
        for (ll j=2;j<=N/i;j++)
            x[i*j]=0;
        i++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SangNt();
    cin>>a>>b;
    for (ll i=a;i<=b;i++)
        if (x[i]==1) cout<<i<<endl;
}

