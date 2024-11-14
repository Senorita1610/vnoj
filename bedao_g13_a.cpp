#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000000;
ll n,ans=0,a[N+5]={};
void Build(){
    for (ll i=1;i<=N;i++)
        for (ll j=1;j<=N/i;j++)
            a[i*j]++;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    Build();
    for (ll i=1;i<=n;i++) ans+=a[i]*a[n-i];
    cout<<ans;
}

