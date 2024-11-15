#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,a[N],x=0,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a[0]=0;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,greater<ll>());
    for (ll i=1;i<=n;i++){
        if (a[i]!=a[i-1]) x++;
        ans+=x;
    }
    cout<<ans;
}

