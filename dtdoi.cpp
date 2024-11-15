#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MaxN=101;
ll n,s,ans=0,a[MaxN],x[50001]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if (s>=20000){
        ans+=(s-20000)/a[n];
        s-=ans*a[n];
    }
    for (ll i=1;i<=s;i++) x[i]=1e+18;
    x[0]=0;
    for (ll i=1;i<=n;i++)
        for (ll j=a[i];j<=s;j++)
            if (x[j-a[i]]!=1e+18) x[j]=min(x[j],x[j-a[i]]+1);
    cout<<ans+x[s];
}

