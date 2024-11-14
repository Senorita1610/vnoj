#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,k,a[N],ans1=0,ans2=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (ll i=1;i<=k;i++) ans1+=a[i];
    for (ll i=n-k;i<n;i++) ans2+=a[i];
    cout<<ans1<<" "<<ans2;
}

