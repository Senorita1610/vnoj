#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005;
ll t,n,a[N];
void Solve(){
    cin>>n;
    ll d=1,m=0;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=2;i<=n;i++)
        if (abs(a[i]-a[i-1])==1) d++;
        else{
            m=max(m,d);
            d=1;
        }
    m=max(m,d);
    if (m*2>n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}

