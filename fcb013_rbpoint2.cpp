#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,a[N],b[N],ans=inf,x=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for (ll i=1;i<=n;i++){
        while (abs(a[i]-b[x])>=abs(a[i]-b[x+1]) && x<n) x++;
        ans=min(ans,abs(a[i]-b[x]));
     }
     cout<<ans;
}

