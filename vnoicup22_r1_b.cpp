#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000000;
ll n,a[N+5],x[2*N+5]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        x[a[i]]++;
    }
    for (ll i=1;i<=N;i++)
        for (ll j=2;j<=N/i;j++)
            x[i]+=x[i*j];
    for (ll i=1;i<=n;i++) cout<<x[a[i]*2]*(x[a[i]*2]-1)/2<<" ";
}

