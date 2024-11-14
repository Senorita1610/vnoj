#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,a[N],x[N],t=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    x[0]=0;
    x[1]=a[1];
    x[2]=a[1]+a[2];
    for (ll i=3;i<=n;i++)
        x[i]=max(max(x[i-1],max(x[i-2],x[i-3])),max(x[i-2]+a[i],x[i-3]+a[i-1]+a[i]));
    cout<<max(x[n],t);
}

