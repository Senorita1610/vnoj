#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll M=1000,inf=1e+18;
ll n,m,ans=-inf,ans1,a[M+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+m+1);
    for (ll i=1;i<=m;i++)
        if (min(m-i+1,n)*a[i]>ans){
            ans=min(m-i+1,n)*a[i];
            ans1=a[i];
        }
    cout<<ans1<<" "<<ans;
}

